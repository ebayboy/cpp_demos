
#include <iostream>
#include <string>
#include <algorithm>

#include <coroutine>
#include <concepts>


// g++ -o test -g -std=c++20 -fcoroutines -DASIO_STANDALONE test.cc

using namespace std;

template<typename T>
concept Promise = requires(T t) { 
	t.promise_coro; 
	t.get_return_object();
	t.initial_suspend();
	t.return_void();
	t.unhandled_exception();
	t.final_suspend();
};

template<typename T>
concept Awaiter = requires(T t) { 
	t.await_ready();
	t.await_suspend(declval<std::coroutine_handle<>>());
	t.await_resume();
};

template <class ReturnObject>
struct LazilyStartedPromise{
	ReturnObject get_return_object() noexcept {
		return ReturnObject{std::coroutine_handle<LazilyStartedPromise<ReturnObject>>::from_promise(*this)};
	}
	suspend_always initial_suspend() noexcept { return {}; }
	void return_void() noexcept {}
	void unhandled_exception() noexcept {}

	struct SymmetricTransferAwaiter { 
		bool await_ready() noexcept { return false; }
		// transfer constrol back to previously stored awaiting coro 
		template<Promise P>
			std::coroutine_handle<> await_suspend(std::coroutine_handle<P> awaiting_coro) noexcept{
				std::cout << "promise_coro_name = " << awaiting_coro.promise().promise_coro_name << std::endl;
				return awaiting_coro.promise().promise_coro; 
			}
		void await_resume() noexcept {}
	};

	SymmetricTransferAwaiter final_suspend() noexcept {return {};}
	coroutine_handle<> promise_coro;
	std::string promise_coro_name;
};

static inline std::string name = "..";

class Awaitable {
	public:
		using promise_type = LazilyStartedPromise<Awaitable>;
		explicit Awaitable(std::coroutine_handle<promise_type> h) noexcept : coro_(h) {}
		Awaitable(Awaitable&& a) noexcept : coro_(std::exchange(a.coro_, {})) {}
		~Awaitable() { if (coro_) coro_.destroy(); }

		struct Awaiter {
			// 
			explicit Awaiter(coroutine_handle<promise_type> awaitable_coro) noexcept : coro(awaitable_coro) {}
			bool await_ready() noexcept { return false; }
			// transfer constrol to the co_awaited coroutine
			// store the awaiting coroutine to promise.coro
			std::coroutine_handle<> await_suspend(
					std::coroutine_handle<> awaiting_coro) noexcept {
				coro.promise().promise_coro = awaiting_coro;
				std::cout << "transfer constrol to the co_awaited coroutine, set promise coro name to " << name << std::endl;
				coro.promise().promise_coro_name = name;
				return coro;
			}
			void await_resume() noexcept {}
			coroutine_handle<promise_type> coro;
		};

		auto operator co_await() noexcept { return Awaiter{coro_}; }
	private:
		coroutine_handle<promise_type> coro_;
};

// Bridging the world of coroutines and that of the normal functions
struct Synchronous {
	struct promise_type {
		Synchronous get_return_object() noexcept {
			return Synchronous{coroutine_handle<promise_type>::from_promise(*this)};
		}
		suspend_never initial_suspend() noexcept { return {}; }
		suspend_always final_suspend() noexcept { return {}; }
		void return_void() noexcept {}
		void unhandled_exception() noexcept {}
	};
	explicit Synchronous(coroutine_handle<promise_type> h) noexcept : coro_(h) {}
	Synchronous(Synchronous&& s) noexcept : coro_(std::exchange(s.coro_, {})) {}
	~Synchronous() {if (coro_) coro_.destroy(); }

	private:
	coroutine_handle<promise_type> coro_;
};

Awaitable inner() {
	std::cout << "... ... ...\n";
	co_return;
}

Awaitable bob() {
	name = "bob";
	co_await inner();
}

Awaitable alice() {
	name = "alice";
	co_await bob();
}

Synchronous start() {
	name = "start";
	co_await alice();
}

int main() 
{
	start();

	return 0;
}
