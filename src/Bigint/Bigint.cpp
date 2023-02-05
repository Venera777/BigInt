#include <BigInt.h>
#include <iostream>
#include <vector>

using namespace std;

namespace ACA
{

    BigInt::BigInt(const string &s)
    {
        digits = "";
        int n = s.size();
        for (int i = n - 1; i >= 0; i--)
        {
            if (!isdigit(s[i]))
                throw("ERROR");
            digits.push_back(s[i] - '0');
        }
    }

    BigInt::BigInt(unsigned long long nr)
    {
        do
        {
            digits.push_back(nr % 10);
            nr /= 10;
        } while (nr);
    }

    BigInt::BigInt(const BigInt &other)
    {
        digits = other.digits;
    }
    BigInt &BigInt::operator++()
    {
        *this += 1;

        return *this;
    }
    BigInt &BigInt::operator--()
    {
        *this -= 1;

        return *this;
    } 
    BigInt BigInt::operator++(int)
    {
        BigInt temp = *this;
        *this += 1;
        return temp;
    }
    BigInt BigInt::operator--(int)
    {
        BigInt temp = *this;
        *this -= 1;
        return temp;
    }
    BigInt &BigInt::operator=(const BigInt &other)
    {
        digits = other.digits;
        return *this;
    }
    bool operator==(const BigInt &lhs, const BigInt &rhs)
    {
        return lhs.digits == rhs.digits;
    }

    bool operator!=(const BigInt &lhs, const BigInt &rhs)
    {
        return !(lhs == rhs);
    }

    bool operator<(const BigInt &lhs, const BigInt &rhs)
    {
        int n = Length(lhs), m = Length(rhs);
        if (n != m)
            return n < m;
        while (n--)
            if (lhs.digits[n] != rhs.digits[n])
                return lhs.digits[n] < rhs.digits[n];
        return false;
    }

    bool operator>(const BigInt &lhs, const BigInt &rhs)
    {
        return rhs < lhs;
    }

    bool operator>=(const BigInt &lhs, const BigInt &rhs)
    {
        return !(lhs < rhs);
    }

    bool operator<=(const BigInt &lhs, const BigInt &rhs)
    {
        return !(lhs > rhs);
    }
   

    BigInt &BigInt::operator+=(const BigInt &rhs)
    {
        *this += rhs;
        return *this;
    }
    BigInt &BigInt::operator-=(const BigInt &rhs)
    {
        *this -= rhs;
        return *this;
    }
    BigInt &BigInt::operator*=(const BigInt &rhs)
    {
        *this = *this * rhs;
        return *this;
    }

    BigInt operator*(BigInt lhs, const BigInt &rhs)
    {
        lhs *= rhs;
        return lhs;
    }

    BigInt &BigInt::operator/=(const BigInt &rhs)
    {
        *this = *this / rhs;
        return *this;
    }

    BigInt operator/(BigInt lhs, const BigInt &rhs)
    {
        lhs /= rhs;
        return lhs;
    }

    BigInt &BigInt::operator%=(const BigInt &rhs)
    {
        *this = *this % rhs;

        return *this;
    }

    BigInt operator%(BigInt lhs, const BigInt &rhs)
    {
        lhs %= rhs;
        return lhs;
    }

    BigInt &BigInt::operator^=(const BigInt &rhs)
    {
        *this = *this ^ rhs;

        return *this;
    }

    BigInt operator^(BigInt lhs, const BigInt &rhs)
    {
        lhs ^= rhs;
        return lhs;
    }

    istream &operator>>(istream &in, BigInt &a)
    {
        string input;
        in >> input;
        a = BigInt(input);
        return in;
    }

    ostream &operator<<(ostream &out, const BigInt &a)
    {
        out << a.toString();
        return out;
    }
    BigInt operator+(const BigInt &a, const BigInt &b)
    {
        BigInt temp;
        temp = a;
        temp += b;
        return temp;
    }
    BigInt operator-(const BigInt &a, const BigInt &b)
    {
        BigInt temp;
        temp = a;
        temp -= b;
        return temp;
    }
}