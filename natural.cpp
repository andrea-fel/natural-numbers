#include "natural.h"
#include <cstring>
#include <string>
#include <random>


void natural::clean0()
{
    int i = nelem-1;
    while (adr[i] == 0) i--;
    if (i >= 0) nelem = i+1;
    else nelem = 1;
}

natural::natural(int size, char val) : arrayof(size)
{
    if (size > 0)
    {
	for (int i=0; i<nelem; i++) adr[i] = val;
    }
}

bool natural::minor(const natural & n) const
{
    if (nelem > n.nelem)
    {
	int i = nelem-1;
	while (adr[i] == 0 && i > n.nelem-1) i--;
	if (i == n.nelem-1)
	{
	    while (adr[i] == n.adr[i] && i > 0) i--;
	    if (adr[i] < n.adr[i]) return true;
	    else return false;
	}	
	else return false;
    }
    else
    {
	if (nelem == n.nelem)
	{
	    int i = nelem-1;
	    while (adr[i] == n.adr[i] && i > 0) i--;
	    if (adr[i] < n.adr[i]) return true;
	    else return false;	    
	}
	else 
	{
	    int i = n.nelem-1;
	    while (n.adr[i] == 0 && i > nelem-1) i--;
	    if (i == nelem-1)
	    {
		while (adr[i] == n.adr[i] && i > 0) i--;
		if (adr[i] < n.adr[i]) return true;
		else return false;
	    }
	    else return true;
	}
    }
}

bool natural::majeq(const natural & n) const
{
    if (nelem > n.nelem)
    {
	int i = nelem-1;
	while (adr[i] == 0 && i > n.nelem-1) i--;
	if (i == n.nelem-1)
	{
	    while (adr[i] == n.adr[i] && i > 0) i--;
	    if (adr[i] >= n.adr[i]) return true;
	    else return false;
	}
	else return true;	
    }
    else
    {
	if (nelem == n.nelem)
	{
	    int i = nelem-1;
	    while (adr[i] == n.adr[i] && i > 0) i--;
	    if (adr[i] >= n.adr[i]) return true;
	    else return false;	    
	}
	else 
	{
	    int i = n.nelem-1;
	    while (n.adr[i] == 0 && i > nelem-1) i--;
	    if (i == nelem-1)
	    {
		while (adr[i] == n.adr[i] && i > 0) i--;
		if (adr[i] >= n.adr[i]) return true;
		else return false;
	    }
	    else return false;
	}
    }
}


natural::natural(int value = 0) : arrayof(digits(value))
{
    for (int i=0; i<nelem; i++)
    {
	adr[i] = value%10;
	value /= 10;
    }
}

natural::natural(const char* digits) : arrayof(strlen(digits))
{
    for (int i=0; i<nelem; i++)
    {
        adr[i] = digits[nelem-i-1]-48;
    }
    this->clean0();
}

natural::natural(std::string digits) : arrayof(digits.size())
{
    for (int i=0; i<nelem; i++)
    {
        adr[i] = digits[nelem-i-1]-48;
    }
    this->clean0();
}


natural operator + (const natural & n, const natural & m)
{
    if  (n.nelem > m.nelem)
    {
	natural sum(n.nelem+1,0);

	for (int i = 0; i < m.nelem; i++)
	{
	    sum.adr[i] += n.adr[i] + m.adr[i];
	    if (sum.adr[i] >= 10) 
	    {
		sum.adr[i] -= 10;	
		sum.adr[i+1] += 1;	
	    }
	}

	for (int i = m.nelem; i < n.nelem; i++)
	{
	    sum.adr[i] += n.adr[i];
	    if (sum.adr[i] >= 10) 
	    {
		sum.adr[i] -= 10;	
		sum.adr[i+1] += 1;	
	    }
	}
	sum.clean0();	
	return sum;
    }
    else
    {
	natural sum(m.nelem+1,0);

	for (int i = 0; i < n.nelem; i++)
	{
	    sum.adr[i] += n.adr[i] + m.adr[i];
	    if (sum.adr[i] >= 10) 
	    {
		sum.adr[i] -= 10;	
		sum.adr[i+1] += 1;	
	    }
	}

	for (int i = n.nelem; i < m.nelem; i++)
	{
	    sum.adr[i] += m.adr[i];
	    if (sum.adr[i] >= 10) 
	    {
		sum.adr[i] -= 10;	
		sum.adr[i+1] += 1;	
	    }
	}
	sum.clean0();
	return sum;
    }
}

natural operator - (const natural & n, const natural & m)
{
    if  (n >= m)
    {
	natural diff(n.nelem, 0);

	for (int i = 0; i < m.nelem; i++)
	{
	    diff.adr[i] += n.adr[i] - m.adr[i];
	    if (diff.adr[i] < 0) 
	    {
		diff.adr[i] += 10;	
		diff.adr[i+1] -= 1;	
	    }
	}

	for (int i = m.nelem; i < n.nelem; i++)
	{
	    diff.adr[i] += n.adr[i];
	    if (diff.adr[i] < 0) 
	    {
		diff.adr[i] += 10;	
		diff.adr[i+1] -= 1;	
	    }
	}
	diff.clean0();
	return diff;
    }
}

/*natural operator * (const natural & n, const natural & m)
{
    natural prod(n.nelem + m.nelem,0);

    for (int i = 0; i < n.nelem; i++)
    {
	for (int j = 0; j < m.nelem; j++)
       	{
	    prod.adr[i+j] += n.adr[i]*m.adr[j];
	    if (prod.adr[i+j] >= 10)
	    {
		char temp = prod.adr[i+j];	    	
		prod.adr[i+j] = temp%10;
            	prod.adr[i+j+1] += temp/10;
	    }
        }
    }
    prod.clean0();
    return prod;    
}*/

natural operator * (const natural & n, const natural & m)
{
    int cut = (n.nelem > m.nelem) ? (n.nelem+1)/2 : (m.nelem+1)/2; 	

    natural product(n.nelem + m.nelem,0);

    if (cut <= 2) 
    {
	for (int i = 0; i < n.nelem; i++)
    	{
	    for (int j = 0; j < m.nelem; j++)
       	    {
	    	product.adr[i+j] += n.adr[i]*m.adr[j];
	    	if (product.adr[i+j] >= 10)
	    	{
		    char temp = product.adr[i+j];	    	
		    product.adr[i+j] = temp%10;
            	    product.adr[i+j+1] += temp/10;
	    	}
            }
    	}
	product.clean0();    	
	return product;
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

	product = product_A + product_B + product_C;
	product.clean0();    	
	return product;
    }
}

natural operator / (const natural & n, const natural & m)
{
    if (m > n) 
    {
	natural quotient(1,0);
	return quotient;
    }
    else
    {	
	int i = 0;
	natural rest(m.nelem+1,0);
	natural quotient(n.nelem,0);	

	while (n.nelem-1-i >= 0)
	{		
	    for (int j = rest.nelem-1; j > 0 ; j--) rest.adr[j] = rest.adr[j-1];
	    rest.adr[0] = n.adr[n.nelem-1-i];
	    
	    if (rest.minor(m)) 
	    {
		for (int j = quotient.nelem-1; j > 0 ; j--) quotient.adr[j] = quotient.adr[j-1];	
		quotient.adr[0] = 0;
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
		} while (rest.majeq(m));

		for (int j = quotient.nelem-1; j > 0 ; j--) quotient.adr[j] = quotient.adr[j-1];
	        quotient.adr[0] = testq;
	    }
	    i++;
	}
	quotient.clean0();
    	return quotient;
    }
}

natural operator % (const natural & n, const natural & m)
{
    if (m > n) 
    {
	return n;
    }
    else
    {	
	int i = 0;
	natural rest(m.nelem+1,0);

	while (n.nelem-1-i >= 0)
	{		
	    for (int j = rest.nelem-1; j > 0 ; j--) rest.adr[j] = rest.adr[j-1];
	    rest.adr[0] = n.adr[n.nelem-1-i];
	    
	    if (rest.majeq(m))
	    {
		do 
		{
		    for (int i = 0; i < m.nelem; i++)
		    {
	    		rest.adr[i] -= m.adr[i];
	    		if (rest.adr[i] < 0) 
	    		{
			    rest.adr[i] += 10;	
			    rest.adr[i+1] -= 1;	
	    		}
		    }
		} while (rest.majeq(m));
	    }
	    i++;
	}
	rest.clean0();
    	return rest;
    }
}

natural operator ^ (const natural & a, const natural & n)
{   
    if (n.nelem == 1 && n.adr[0] == 1) return a;
    else
    {
	natural m = n%2;
	if (m.nelem == 1 && m.adr[0] == 0) return (a*a)^(n/2);
	else return a*((a*a)^((n-1)/2));
    }
}


int natural::digits(int value)
{
    if (value >= 0)
    {
	int tmp = value;
	int numdig = 0;
	do 
	{
	    tmp /= 10;
	    numdig++;
	} while (tmp != 0);
    return numdig;
    }
}


void natural::display()
{
    for (int i = nelem-1; i >= 0; i--) std::cout << int(adr[i]);
    std::cout << std::endl;
}


int random_int(int start, int stop)
{ 
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(start,stop);

    return dis(gen);
}

natural random_natural(int digits)
{   
    natural trial(digits, 0);

    for (int i = 0; i < digits-1; ++i) trial[i] = (char)random_int(0,9);

    trial[digits-1] = (char)random_int(1,9);

    return trial;
}


natural random_natural(const natural & n, const natural & m)
{
    if (n <= m)
    {
	natural trial(m.nelem, 0);

	do
	{
            for (int i = 0; i < m.nelem; i++) trial[i] = (char)random_int(0,9);
	} while (trial.minor(n) || m.minor(trial)); 

	trial.clean0();
	return trial;
    }    
}


natural gcd(const natural & n, const natural & m)
{
    natural zero = 0;
    if (m == zero) return n;
    else return gcd(m,n%m);
}
