#include "LinearProbing.h"
using namespace std;
#define p(arr)         \
    for (auto i : arr) \
        cout << i << "\n";
vector<int> LinearProbing::merge(vector<int> a, vector<int> b)
{
    int m = 0, n = 0, k = 0;
    vector<int> s;
    while (m < a.size() && n < b.size())
    {
        if (a[m] >= b[n])
        {
            s.push_back(a[m]);
            k++;
            m++;
        }
        else
        {
            s.push_back(b[n]);
            n++;
            k++;
        }
    }
    while (m < a.size())
    {
        s.push_back(a[m]);
        k++;
        m++;
    }
    while (n < b.size())
    {
        s.push_back(b[n]);
        k++;
        n++;
    }
    return s;
}
vector<int> LinearProbing::sort(vector<int> a)
{
    if (a.size() <= 1)
    {
        return a;
    }
    else
    {
        auto b = a.begin();
        auto c = a.begin() + (a.size()) / 2;
        auto d = a.end();
        vector<int> v1;
        vector<int> v2;
        v1.assign(b, c);
        v2.assign(c, d);
        vector<int> a = sort(v1);
        vector<int> e = sort(v2);
        return merge(a, e);
    }
}
void LinearProbing::createAccount(std::string id, int count)
{
    if (bankStorage1d.size() <= 0)
    {
        Account b;
        b.id = "UN";
        b.balance = -1;
        vector<Account> a(100000, b);
        bankStorage1d = a;
    }
    int i = hash(id);
    while (bankStorage1d[i % 100000].balance != -1 && bankStorage1d[i % 100000].balance != -2)
    {
        i += 1;
    }
    if (bankStorage1d[i % 100000].balance != -2)
    {
        Sort_Balance.push_back(i);
    }
    i = i % 100000;
    bankStorage1d[i].balance = count;
    bankStorage1d[i].id = id;
    size += 1;
}

std::vector<int> LinearProbing::getTopK(int k)
{
    vector<int> a;
    for (auto i : Sort_Balance)
    {
        a.push_back((bankStorage1d)[i].balance);
    }
    vector<int> b = sort(a);
    a.clear();
    // p(b);
    for (int i = 0; i < k; i++)
    {
        a.push_back(b[i]);
    }
    return a;
}

int LinearProbing::getBalance(std::string id)
{
    int i = hash(id);
    while ((bankStorage1d[(i % 100000)]).balance != -1 && bankStorage1d[(i % 100000)].id != id)
    {
        i++;
    }
    if (bankStorage1d[(i % 100000)].balance < 0)
    {
        return -1;
    }
    return bankStorage1d[(i % 100000)].balance;
}

void LinearProbing::addTransaction(std::string id, int count)
{
    int i = hash(id);
    while ((bankStorage1d[(i % 100000)]).balance != -1 && bankStorage1d[(i % 100000)].id != id)
    {
        i++;
    }
    i = i % 100000;
    if (bankStorage1d[(i)].balance >= 0)
    {
        // cout
        //     << id << "Here\n";
        int t = bankStorage1d[(i)].balance;
        bankStorage1d[i].balance += count;
    }
    else
    {
        if ((bankStorage1d[(i % 100000)]).balance != -2)
        {
            Sort_Balance.push_back(i);
        }
        bankStorage1d[i].id = id;
        bankStorage1d[i].balance = count;
        size += 1;
    }
}

bool LinearProbing::doesExist(std::string id)
{
    int i = hash(id);
    while ((bankStorage1d[(i % 100000)]).balance != -1 && bankStorage1d[(i % 100000)].id != id && i < 200000)
    {
        i++;
    }
    if (i > 200000 || bankStorage1d[(i % 100000)].balance == -2 || bankStorage1d[(i % 100000)].balance == -1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool LinearProbing::deleteAccount(std::string id)
{
    int i = hash(id);
    while ((bankStorage1d[(i % 100000)]).balance != -1 && bankStorage1d[(i % 100000)].id != id && i < 200000)
    {
        i++;
    }
    i = i % 100000;
    if (i > 200000 || bankStorage1d[(i)].balance < 0)
    {
        return false;
    }
    else
    {
        bankStorage1d[(i)].balance = -2;
        size -= 1;
        return true;
    }
}
int LinearProbing::databaseSize()
{
    return size;
}

int LinearProbing::hash(std::string id)
{
    static const int hashPrime = 100003;
    int r = stoi(id.substr(4, 7)) % hashPrime + (stoi(id.substr(12, 5))) % hashPrime + stoi(id.substr(17, 5)) % hashPrime;

    int sum = int(id[0]) + 2 * int(id[1]) + 3 * int(id[2]) + 4 * int(id[3]);
    return abs((r - sum) % 100003 - 3);
}