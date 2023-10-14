/////////////// Name - Mann Chandarana
/////////////// Rollno - 20CS011

#include <iostream>
#include <math.h>
#include <bitset>
using namespace std;

int binaryToDecimal(string s)
{
    int result = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[s.length() - i - 1] == '1')
        {
            result += pow(2, i);
        }
    }
    return result;
}

string decimalToBinary(int n)
{
    return bitset<4>(n).to_string();
}

string invert(string s)
{
    string result = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
        {
            result += '1';
        }
        else
        {
            result += '0';
        }
    }
    return result;
}

string twosComplement(string s)
{
    string result = invert(s);
    int dec = (binaryToDecimal(result) + 1) % 16;
    return decimalToBinary(dec);
}

string ashr(string s)
{
    string result;
    result += s[0];
    result += s.substr(0, s.length() - 1);
    return result;
}

int main()
{
    cout << "\n***********************************" << endl;
    cout << "Name - Mann Chandarana" << endl;
    cout << "Rollno - 20CS011" << endl;
    cout << "***********************************" << endl;
    string a;
    string b;

    int as;
    int bs;
    char resultSign;

    cout << "Enter A(4-bit): ";
    cin >> a;
    cout << "Enter sign(0-1): ";
    cin >> as;

    cout << "Enter B(4-bit): ";
    cin >> b;
    cout << "Enter sign(0-1): ";
    cin >> bs;

    if (as != bs)
    {
        resultSign = '-';
    }
    else
    {
        resultSign = '+';
    }

    string ac = "0000";
    string br = a;
    string qr = b;
    int sc = 4;
    char qn1 = '0';
    char qn = qr[qr.length() - 1];

    while (sc--)
    {

        if (qn == '1' && qn1 == '0')
        {
            ac = decimalToBinary(binaryToDecimal(ac) + binaryToDecimal(twosComplement(br)));
        }
        else if (qn == '0' && qn1 == '1')
        {
            ac = decimalToBinary(binaryToDecimal(ac) + binaryToDecimal(br));
        }

        string result = ashr(ac + qr + qn1);
        ac = result.substr(0, 4);
        qr = result.substr(4, 4);
        qn = qr[qr.length() - 1];
        qn1 = result[result.length() - 1];
    }

    cout << "Result: " << resultSign << binaryToDecimal(ac + qr) << endl;

    return 0;
}