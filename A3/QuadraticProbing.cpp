#include "QuadraticProbing.h"
int QuadraticProbing::find(int num)
{
    int p = 0;
    int q = Sort_Balance.size() - 1;
    while (true)
    {
        if ((Sort_Balance[(p + q) >> 1]) == num)
        {
            return ((p + q) >> 1);
        }
        else
        {
            if (p >= q)
            {
                if (Sort_Balance[p] > num)
                {
                    return (p + 1);
                }
                else
                {
                    return (p);
                }
            }
            else if (((Sort_Balance[(p + q) >> 1]) < num))
            {
                q = ((p + q) >> 1) - 1;
            }
            else
            {
                p = ((p + q) >> 1) + 1;
            }
        }
    }
}
void QuadraticProbing::createAccount(std::string id, int count)
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
    int j = 1;
    while (bankStorage1d[i % 100000].balance != -1 && bankStorage1d[i % 100000].balance != -2)
    {
        i += (j * j);
        j += 1;
    }
    i = i % 100000;
    bankStorage1d[i].balance = count;
    bankStorage1d[i].id = id;
    size += 1;
    if (Sort_Balance.size() <= 0)
    {
        Sort_Balance.push_back(count);
    }
    else
    {
        Sort_Balance.push_back(0);
        int t = find(count);
        Sort_Balance.insert(Sort_Balance.begin() + t, count);
    }
}

std::vector<int> QuadraticProbing::getTopK(int k)
{
    vector<int> a;
    for (int i = 0; i < k; i++)
    {
        a.push_back(Sort_Balance[i]);
    }
    return a;
}

int QuadraticProbing::getBalance(std::string id)
{
    int i = hash(id);
    int j = 1;
    while ((bankStorage1d[(i % 100000)]).balance != -1 && bankStorage1d[(i % 100000)].id != id)
    {
        i += j * j;
        j += 1;
    }
    if ((bankStorage1d[(i % 100000)]).balance < 0)
    {
        return -1;
    }
    return bankStorage1d[(i % 100000)].balance;
}

void QuadraticProbing::addTransaction(std::string id, int count)
{
    int i = hash(id);
    int j = 1;
    while ((bankStorage1d[(i % 100000)]).balance != -1 && bankStorage1d[(i % 100000)].id != id && i < 500000)
    {
        i += j * j;
        j += 1;
    }
    i = i % 100000;
    // cout << bankStorage1d[(i)].balance << endl;
    if (bankStorage1d[(i)].balance >= 0)
    {
        int t = bankStorage1d[(i)].balance;
        bankStorage1d[i].balance += count;
        int r = bankStorage1d[i].balance;
        int i = find(t);
        int j = find(r);
        if (count > 0)
        {
            while (i != j)
            {
                Sort_Balance[i] = Sort_Balance[i - 1];
                i--;
            }
            Sort_Balance[j] = r;
        }
        else if (count < 0)
        {
            while (j - i > 1)
            {
                Sort_Balance[i] = Sort_Balance[i + 1];
                i++;
            }
            Sort_Balance[j - 1] = r;
        }
    }
    else
    {
        bankStorage1d[i].id = id;
        bankStorage1d[i].balance = count;
        size += 1;
        if (Sort_Balance.size() <= 0)
        {
            Sort_Balance.push_back(count);
        }
        else
        {
            Sort_Balance.push_back(0);
            int i = find(count);
            Sort_Balance.insert(Sort_Balance.begin() + i, count);
        }
    }
}

bool QuadraticProbing::doesExist(std::string id)
{
    int i = hash(id);
    int j = 1;
    while ((bankStorage1d[(i % 100000)]).balance != -1 && bankStorage1d[(i % 100000)].id != id && i < 500000)
    {
        i += j * j;
        j += 1;
    }
    if (i > 500000 || bankStorage1d[(i % 100000)].balance == -2 || bankStorage1d[(i % 100000)].balance == -1)
    {
        return false;
    }
    else
    {
        return true;
    }
    return false;
}

bool QuadraticProbing::deleteAccount(std::string id)
{
    int i = hash(id);
    int j = 1;
    while ((bankStorage1d[(i % 100000)]).balance != -1 && bankStorage1d[(i % 100000)].id != id && i < 500000)
    {
        i += j * j;
        j += 1;
    }
    i = i % 100000;
    if (i > 500000 || bankStorage1d[i].balance < 0)
    {
        return false;
    }
    else
    {
        int j = find(bankStorage1d[(i)].balance);
        Sort_Balance.erase(Sort_Balance.begin() + j);
        bankStorage1d[(i)].balance = -2;
        size -= 1;
        return true;
    }
}
int QuadraticProbing::databaseSize()
{
    return size;
}

int QuadraticProbing::hash(std::string id)
{
    static const int hashPrime = 100003;
    int r = stoi(id.substr(4, 7)) % hashPrime + (stoi(id.substr(12, 5))) % hashPrime + stoi(id.substr(17, 5)) % hashPrime;

    int sum = int(id[0]) + 2 * int(id[1]) + 3 * int(id[2]) + 4 * int(id[3]);
    return abs((r - sum) % 100003 - 3);
}