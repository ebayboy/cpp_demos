#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

#include <string.h>

using namespace std;

#define CONF_ENCRYPT_MASK       "j+#1)-d<,:"  /* 需和控制面保持一致 */

static void 
waf_conf_file_decrypt(char *data, int len) 
{
        int n, m;
        char *mask = (char *)CONF_ENCRYPT_MASK;

        cout << "len:" << len << endl;

        for (n = 0; n < len; n++) {
                m = n % (sizeof(CONF_ENCRYPT_MASK) - 1);
                data[n] ^= mask[m];
        }    
}

int txt_read(const char *fname, string &data)
{

        std::stringstream buffer;  

        fstream f(fname, ios::in);

        if (f.bad()) {

                return -1;
        }

        buffer << f.rdbuf();
        data = buffer.str();

        f.close();

        return 0;
}

/* write to file */
int txt_write(const char* fname, string data)
{
        ofstream f(fname);
        if (f.bad()) {
                return -1;
        }

        f << data;
        f.close();

        return 0;
}

int main(int argc, char **argv)
{
        string data;

        txt_read("/etc/nginx/waf.dat", data);

        char *cData = (char *)malloc(data.size() + 1);
        memset(cData, 0, data.size() + 1);
        memcpy(cData, data.c_str(), data.size());

        waf_conf_file_decrypt(cData, data.size());
        txt_write("/etc/nginx/waf.dat.dec", cData);

        if (cData)
                free(cData);

        return 0;
}