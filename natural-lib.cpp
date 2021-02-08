#include "natural-lib.h"
#include <iostream>
#include <cstring>
#include <random>


natural::natural(int size, int val) 
{
    if (size > 0)
    {
    	nelem = size;
    	adr = new char [nelem];
		for (int i = 0; i < nelem; ++i) adr[i] = (char) val;
    }
    else
    {
    	nelem = 1;
    	adr = new char [nelem];
    	adr[nelem] = val;
    }
}


void natural::clean0()
{
    int i = nelem-1;
    while (adr[i] == 0) i--;
    if (i >= 0) nelem = i+1;
    else nelem = 1;
}


int digits(int value)
{
    int numberOfDigits = 0;
    if (value >= 0)
    {
		int temp = value;
		do 
		{
	    	temp /= 10;
	    	numberOfDigits++;
		} while (temp != 0);
    }
    return numberOfDigits;
}


int natural::findIndex(const natural & n) const
{
    natural bigIndex = (nelem > n.nelem) ? *this : n;
    natural smallIndex = (nelem > n.nelem) ? n : *this;
    
	int i = bigIndex.nelem - 1;
	while (bigIndex.adr[i] == 0 && i > smallIndex.nelem - 1) i--;
	if (i == smallIndex.nelem - 1)
	{
		while (bigIndex.adr[i] == smallIndex.adr[i] && i > 0) i--;
	}	
	
	return i;
}


bool natural::isSmallerThan(const natural & n) const
{   
    int index = this -> findIndex(n);

    if (index >= nelem) return true;
    else
    {
    	if (index >= n.nelem) return false;
    	else
    	{
    		if (adr[index] < n.adr[index]) return true;
	   		else return false;
		}
    }
}


bool natural::isLargerOrEqualTo(const natural & n) const
{
    int index = this -> findIndex(n);

    if (index >= nelem) return false;
    else
    {
    	if (index >= n.nelem) return true;
    	else
    	{
    		if (adr[index] >= n.adr[index]) return true;
	   		else return false;
		}
    }
}


char randomInt(int start, int stop)
{ 
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(start,stop);
    return (char) dis(gen);
}


natural::natural(int value = 0)
{
    nelem = digits(value);
    adr = new char [nelem];
    for (int i = 0; i < nelem; i++)
    {
		adr[i] = value%10;
		value /= 10;
    }
}


natural::natural(const char* digits)
{
    nelem = strlen(digits);
    adr = new char [nelem];
    for (int i=0; i<nelem; i++)
    {
        adr[i] = digits[nelem-i-1] - '0';
    }
    this -> clean0();
}


natural::natural(std::string digits)
{
    nelem = digits.size();
    adr = new char [nelem];
    for (int i = 0; i < nelem; i++)
    {
        adr[i] = digits[nelem - i - 1] - '0';
    }
    this -> clean0();
}


natural::~natural()
{
    delete [] adr;
}


natural::natural(const natural & n)
{
    nelem = n.nelem;
    adr = new char [nelem];
    for (int i = 0; i < nelem; i++) adr[i] = n.adr[i];
}


natural & natural::operator = (const natural & n)
{
    if (this != &n)
    {
		delete [] adr;
		nelem = n.nelem;
		adr = new char [nelem];
		for (int i = 0; i < nelem; i++) adr[i] = n.adr[i];
    }
    return *this;
}


char & natural::operator [] (int i) const
{
    return adr[i];
}


int natural::size() const
{
	return nelem;
}


void natural::display()
{
    for (int i = nelem - 1; i >= 0; i--) std::cout << (int) adr[i];
    std::cout << std::endl;
}


bool operator > (const natural & n, const natural & m)
{
    if (n.nelem > m.nelem) return true;
    else
    {
		if (n.nelem == m.nelem)
		{
	    	int i = n.nelem - 1;
	    	while (n.adr[i] == m.adr[i] && i > 0) i--;
	    	if (n.adr[i] > m.adr[i]) return true;
	    	else return false;	    
		}
		else return false;
    }
}


bool operator >= (const natural & n, const natural & m)
{
    if (n.nelem > m.nelem) return true;
    else
    {
		if (n.nelem == m.nelem)
		{
	    	int i = n.nelem - 1;
	    	while (n.adr[i] == m.adr[i] && i > 0) i--;
	    	if (n.adr[i] >= m.adr[i]) return true;
	    	else return false;	    
		}
		else return false;
    }
}


bool operator < (const natural & n, const natural & m)
{
    if (n.nelem < m.nelem) return true;
    else
    {
		if (n.nelem == m.nelem)
		{
	    	int i = n.nelem - 1;
	    	while (n.adr[i] == m.adr[i] && i > 0) i--;
	    	if (n.adr[i] < m.adr[i]) return true;
	    	else return false;	    
		}
		else return false;
    }
}


bool operator <= (const natural & n, const natural & m)
{
    if (n.nelem < m.nelem) return true;
    else
    {
		if (n.nelem == m.nelem)
		{
	    	int i = n.nelem - 1;
	    	while (n.adr[i] == m.adr[i] && i > 0) i--;
	    	if (n.adr[i] <= m.adr[i]) return true;
	    	else return false;	    
		}
		else return false;
    }
}


bool operator == (const natural & n, const natural & m)
{
    if (n.nelem == m.nelem)
    {
		int i = n.nelem - 1;
		while (n.adr[i] == m.adr[i] && i > 0) i--;
		if (n.adr[i] == m.adr[i]) return true;
		else return false;	    
    }
    else return false;
}


bool operator != (const natural & n, const natural & m)
{
    if (n.nelem == m.nelem)
    {
		int i = n.nelem - 1;
		while (n.adr[i] == m.adr[i] && i > 0) i--;
		if (n.adr[i] != m.adr[i]) return true;
		else return false;	    
    }
    else return true;
}


natural & natural::operator += (const natural & n)
{
	natural large = (nelem > n.nelem) ? *this : n;
    natural small = (nelem > n.nelem) ? n : *this;
    
	delete [] adr;
	nelem = large.nelem + 1;
	adr = new char [nelem];
	for (int i = 0; i < large.nelem + 1; i++) adr[i] = 0;

	for (int i = 0; i < small.nelem; i++)
	{
	    adr[i] += large.adr[i] + small.adr[i];
	    if (adr[i] >= 10) 
	    {
			adr[i] -= 10;	
			adr[i+1] += 1;	
	    }
	}

	for (int i = small.nelem; i < large.nelem; i++)
	{
	    adr[i] += large.adr[i];
	    if (adr[i] >= 10) 
	    {
			adr[i] -= 10;	
			adr[i+1] += 1;	
	    }
	}
	
	this -> clean0();
	return *this; 
}


natural & natural::operator -= (const natural & m)
{
    if  (*this >= m)
    {
    	natural n = *this;
    	delete [] adr;
    	nelem = n.nelem;
    	adr = new char [nelem];
    	for (int i = 0; i < nelem; i++) adr[i] = 0;
    	
		for (int i = 0; i < m.nelem; i++)
		{
	    	adr[i] += n.adr[i] - m.adr[i];
	    	if (adr[i] < 0) 
	    	{
				adr[i] += 10;	
				adr[i+1] -= 1;	
	    	}
		}

		for (int i = m.nelem; i < n.nelem; i++)
		{
	   		adr[i] += n.adr[i];
	    	if (adr[i] < 0) 
	    	{
				adr[i] += 10;	
				adr[i+1] -= 1;	
	    	}
		}
		this -> clean0();
		return *this;
    }
}


natural & natural::operator *= (const natural & m)
{
	int cut = (nelem > m.nelem) ? (nelem+1)/2 : (m.nelem+1)/2; 	

    natural n = *this;
    delete [] adr;
    nelem = n.nelem + m.nelem;
    adr = new char [nelem];
    for (int i = 0; i < nelem; i++) adr[i] = 0;

    if (cut <= 2) 
    {
		for (int i = 0; i < n.nelem; i++)
    	{
	    	for (int j = 0; j < m.nelem; j++)
       	    {
	    		adr[i+j] += n.adr[i]*m.adr[j];
	    		if (adr[i+j] >= 10)
	    		{
		    		char temp = adr[i+j];	    	
		    		adr[i+j] = temp%10;
            	    adr[i+j+1] += temp/10;
	    		}
            }
    	}
		this -> clean0();    	
		return *this;
    }
    else
    {
    	natural product_A(1,0), product_B(4*cut,0), product_C(4*cut,0), temp_B(1,0), temp_C(1,0);
    	natural temp_A1(cut,0), temp_A2(cut,0), temp_B1(cut,0), temp_B2(cut,0);
	
		for (int i = 0; i < ((cut < n.nelem) ? cut : n.nelem); i++) temp_A1.adr[i] = n.adr[i]; 
		for (int i = 0; i < ((cut < m.nelem) ? cut : m.nelem); i++) temp_A2.adr[i] = m.adr[i];
		product_A = temp_A1*temp_A2;   	

		for (int i = cut; i < n.nelem; i++) temp_B1.adr[i-cut] = n.adr[i];   	
		for (int i = cut; i < m.nelem; i++) temp_B2.adr[i-cut] = m.adr[i];
		temp_B = temp_B1*temp_B2; 

    	temp_C = (temp_A1 + temp_B1)*(temp_A2 + temp_B2) - product_A - temp_B;

		for (int i = 0; i < temp_B.nelem; i++) product_B.adr[i+2*cut] = temp_B.adr[i];	
		for (int i = 0; i < temp_C.nelem; i++) product_C.adr[i+cut] = temp_C.adr[i];	

		*this = product_A + product_B + product_C;
		this -> clean0();    	
		return *this;
    }
}


natural & natural::operator /= (const natural & m)
{
	if (m > *this) 
    {
		delete [] adr;
		nelem = 1;
		adr = new char [nelem];
		adr[0] = 0;
		return *this;
    }
    else
    {	
		int i = 0;
		natural n = *this;
		delete [] adr;
		nelem = n.nelem;
		adr = new char [nelem];
		for (int i = 0; i < nelem; i++) adr[i] = 0;
		natural rest(m.nelem+1,0);	

		while (n.nelem-1-i >= 0)
		{		
	    	for (int j = rest.nelem-1; j > 0 ; j--) rest.adr[j] = rest.adr[j-1];
	    	rest.adr[0] = n.adr[n.nelem-1-i];
	    
	    	if (rest.isSmallerThan(m)) 
	    	{
				for (int j = nelem-1; j > 0 ; j--) adr[j] = adr[j-1];	
				adr[0] = 0;
	    	}
	    	else
	    	{
				char testq = 0;
				do 
				{
		    		testq++;
		    		for (int k = 0; k < m.nelem; k++)
		    		{
	    				rest.adr[k] -= m.adr[k];
	    				if (rest.adr[k] < 0) 
	    				{
			    			rest.adr[k] += 10;	
			    			rest.adr[k+1] -= 1;	
	    				}
		    		}
				} while (rest.isLargerOrEqualTo(m));

				for (int j = nelem-1; j > 0 ; j--) adr[j] = adr[j-1];
	        	adr[0] = testq;
	    	}
	    	i++;
		}
		this -> clean0();
    	return *this;
    }
}


natural & natural::operator %= (const natural & m)
{
	if (m > *this) 
    {
		return *this;
    }
    else
    {	
		int i = 0;
		natural n = *this;
		delete [] adr;
		nelem = m.nelem + 1;
		adr = new char [nelem];
		for (int i = 0; i < nelem; i++) adr[i] = 0;

		while (n.nelem-1-i >= 0)
		{		
	    	for (int j = nelem-1; j > 0 ; j--) adr[j] = adr[j-1];
	    	adr[0] = n.adr[n.nelem-1-i];
	    
	    	if (this -> isLargerOrEqualTo(m))
	    	{
				do 
				{
		    		for (int i = 0; i < m.nelem; i++)
		    		{
	    				adr[i] -= m.adr[i];
	    				if (adr[i] < 0) 
	    				{
			    			adr[i] += 10;	
			    			adr[i+1] -= 1;	
	    				}
		    		}
				} while (this -> isLargerOrEqualTo(m));
	    	}
	    	i++;
		}
		this -> clean0();
    	return *this;
    }
}


natural & natural::operator ++ ()
{
	natural n = *this;
	delete [] adr;
	nelem = n.nelem + 1;
	adr = new char [nelem];
	adr[0] = 1;
	for (int i = 1; i < nelem; i++) adr[i] = 0;

	for (int i = 0; i < n.nelem; i++)
	{
	    adr[i] += n.adr[i];
	    if (adr[i] >= 10) 
	    {
			adr[i] -= 10;	
			adr[i+1] += 1;	
	    }
	}
	this -> clean0();
	return *this;
}


natural natural::operator ++ (int)
{
	natural n = *this;
	++(*this);
	return n;
}


natural & natural::operator -- ()
{
	if (*this > 0) 
	{
		int i = 0;
		adr[i] -= 1;
	
		while (adr[i] < 0) 
		{
			adr[i] += 10;	
			adr[i+1] -= 1;
			i++;	
		}
		this -> clean0();
		return *this;
	}
	return *this;
}


natural natural::operator -- (int)
{
	natural n = *this;
	--(*this);
	return n;
}


natural operator + (natural n, const natural & m)
{
    n += m;
	return n;
}


natural operator - (natural n, const natural & m)
{
	n -= m;
	return n;
}


natural operator * (natural n, const natural & m)
{
    n *= m;
    return n;
}


natural operator / (natural n, const natural & m)
{
	n /= m;
	return n;
}


natural operator % (natural n, const natural & m)
{
    n %= m;
    return n;
}


natural operator ^ (const natural & a, const natural & n)
{   
    if (n == 1) return a;
    else
    {
		if (n%2 == 0) return (a*a)^(n/2);
		else return a*((a*a)^((n-1)/2));
    }
}


natural randomNatural(int digits)
{   
    natural trial(digits, 0);
    for (int i = 0; i < digits-1; ++i) trial[i] = randomInt(0,9);
    trial[digits-1] = randomInt(1,9);
    return trial;
}


natural randomNatural(const natural & n, const natural & m)
{
    if (n <= m)
    {
		natural trial(m.nelem, 0);
		do
		{
    		for (int i = 0; i < m.nelem; i++) trial[i] = randomInt(0,9);
		} while (trial.isSmallerThan(n) || m.isSmallerThan(trial)); 
		trial.clean0();
		return trial;
    }    
}


natural gcd(const natural & n, const natural & m)
{
    if (m == 0) return n;
    else return gcd(m,n%m);
}

