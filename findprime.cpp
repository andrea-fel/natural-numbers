#include <iostream>
#include <chrono>
#include "natural.h"

using namespace std;

int main()
{
    natural prime(const int);
    natural prime(const natural &);
    natural public_key(const int, const natural &);
    natural private_key(const natural &, const natural &);

    natural p(0), q(0), r(0), e(0), d(0);
    int digits = 20;

    p = prime(digits);
    q = prime(digits);

    r = (p-1)*(q-1);

    e = public_key(7,r);
    auto start = chrono::steady_clock::now();
    d = private_key(e,r);
    auto end = chrono::steady_clock::now();
    r.display();    
    e.display();
    d.display();
    ((e*d)%r).display();



    chrono::duration<double> elapsed_seconds = end-start;
    cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

    return 0;
}


natural prime(const int digits)
{
    natural random_natural(int);
    natural random_natural(const natural &, const natural &);
    bool witness_1(natural &, natural &);
    //bool witness_2(natural &, natural &);

    int i = 0;
    bool check = false;
    natural two = 2;
    natural wit(0);
    natural trial(0);

    while (i < 50)
    {
	i = 0;
	trial = random_natural(digits);

	do
	{
	    wit = random_natural(two, trial-1);
	    check = witness_1(wit, trial);
	    i++;
	} while (check == false && i < 50);
    }
    return trial;
}


natural prime(const natural & value)
{
    natural random_natural(const natural &, const natural &);
    bool witness_1(natural &, natural &);
    //bool witness_2(natural &, natural &);

    int i = 0;
    bool check = false;
    natural two = 2;
    natural wit(0);
    natural trial(0);

    while (i < 50)
    {
	i = 0;
	trial = random_natural(two, value-1);

	do
	{
	    wit = random_natural(two, trial-1);
	    check = witness_1(wit, trial);
	    i++;
	} while (check == false && i < 50);
    }
    return trial;
}

bool witness_1(natural & a, natural & n)
{
    natural mod_exp(const natural &, const natural &, const natural &);

    natural one = 1;
    natural param = mod_exp(a,n-1,n);
    bool check1 = (param != one);

    return check1;
}


natural mod_exp(const natural & a, const natural & n, const natural & m)
{
    natural zero = 0;
    natural one = 1;
    if (n == one) return a;
    else
    {
	if (n%2 == zero) return (mod_exp((a*a)%m,n/2, m))%m;
	else return (a*mod_exp((a*a)%m,(n-1)/2, m))%m;
    }
}

/*bool witness_2(natural & a, natural & n)
{
    natural gcd(const natural &, const natural &);

    natural m = n-1;
    while (m%2 == 0)
    {
	m = m/2;	
    }

    natural one = 1;
    natural param = (a^m) - one;
    param = gcd(n, param);

    bool check2 = (one < param) && (param < n);

}*/


natural public_key(const natural & value)
{
    natural prime(const natural &);
    natural one = 1;
    natural trial(0);
    do
    {
	trial = prime(value);
    } while (gcd(value,trial) != one);

    return trial;
}


natural public_key(const int digits, const natural & value)
{
    natural prime(const int);
    natural one = 1;
    natural trial(0);
    do
    {
	trial = prime(digits);
    } while (gcd(value,trial) != one);

    return trial;
}


natural private_key(const natural & key, const natural & value)
{
    natural zero = 0;
    natural remainder = value%key;
    natural target = key - 1;

    while (target%remainder != zero)
    {
	target = target + key;
    }

    return ((target/remainder)*value)/key+1;
}



