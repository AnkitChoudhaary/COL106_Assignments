#include "Chaining.h"
using namespace std;
int Chaining::find(int num, vector<int> Sort_Balance)
{

    int p = 0;
    int q = Sort_Balance.size() - 1;
    while (true)
    {
        if ((Sort_Balance[(p + q) >> 1]) == num)
        {
            // cout << "Yep\n;";
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
void Chaining::createAccount(std::string id, int count)
{
    if (bankStorage2d.size() <= 0)
    {
        bankStorage2d.resize(100000);
    }
    int i = hash(id);
    Account a;
    a.balance = count;
    a.id = id;
    bankStorage2d[i].push_back(a);
    size += 1;
    if (Sort_Balance.size() <= 0)
    {
        Sort_Balance.push_back(count);
    }
    else
    {
        // Sort_Balance.push_back(0);
        int t = find(count, Sort_Balance);
        Sort_Balance.insert(Sort_Balance.begin() + t, count);
    }
}

std::vector<int> Chaining::getTopK(int k)
{
    vector<int> a;
    for (int i = 0; i < k; i++)
    {
        a.push_back(Sort_Balance[i]);
    }
    return a;
}

int Chaining::getBalance(std::string id)
{
    int i = hash(id);
    for (auto it : bankStorage2d[i])
    {
        if ((it).id == id)
        {
            return it.balance;
        }
    }
    return -1; // Placeholder return value
}

void Chaining::addTransaction(std::string id, int count)
{
    int i = hash(id);
    int t, r;
    bool z = false;
    for (int j = 0; j < bankStorage2d[i].size(); j++)
    {
        if (bankStorage2d[i][j].id == id && bankStorage2d[i][j].balance >= 0)
        {
            t = bankStorage2d[i][j].balance;
            bankStorage2d[i][j].balance += count;

            r = bankStorage2d[i][j].balance;
            z = true;
            break;
        }
    }
    if (!z)
    {

        Account temp;
        temp.id = id;
        temp.balance = count;
        if (Sort_Balance.size() <= 0)
        {
            Sort_Balance.push_back(count);
        }
        else
        {
            int i = find(count, Sort_Balance);
            Sort_Balance.insert(Sort_Balance.begin() + i, count);
        }
        bankStorage2d[i].push_back(temp);
        size += 1;
    }
    else
    {
        int i = find(t, Sort_Balance);
        int j = find(r, Sort_Balance);
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
}

bool Chaining::doesExist(std::string id)
{
    int i = hash(id);
    for (auto it : bankStorage2d[i])
    {
        if ((it).id == id && it.balance >= 0)
        {
            return true;
        }
    }
    return false;
    // return false; // Placeholder return value
}

bool Chaining::deleteAccount(std::string id)
{
    int i = hash(id);
    for (int j = 0; j < bankStorage2d[i].size(); j++)
    {
        if (bankStorage2d[i][j].id == id)
        {
            // cout << "Here\n";
            // cout << bankStorage2d[i][j].balance << "\n";
            // cout << bankStorage2d[i][j].balance << "\n";
            if (bankStorage2d[i][j].balance >= 0)
            {
                int a = find(bankStorage2d[i][j].balance, Sort_Balance);
                // cout << "Here\n"
                //  << bankStorage2d[i][j].id << "\n";
                bankStorage2d[i].erase(bankStorage2d[i].begin() + j);
                // cout << Sort_Balance.size() << " " << a << endl;
                Sort_Balance.erase(Sort_Balance.begin() + a);
                size -= 1;
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    return false; // Placeholder return value
}
int Chaining::databaseSize()
{
    return size;
}

int Chaining::hash(std::string id)
{
    static const int hashPrime = 100003;
    int r = stoi(id.substr(4, 7)) % hashPrime + (stoi(id.substr(12, 5))) % hashPrime + stoi(id.substr(17, 5)) % hashPrime;

    int sum = int(id[0]) + 2 * int(id[1]) + 3 * int(id[2]) + 4 * int(id[3]);
    return abs((r - sum) % 100003 - 3);
}