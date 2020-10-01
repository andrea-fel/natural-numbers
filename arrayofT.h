#include <iostream>

template <typename T> class arrayof
{
    protected:
      int nelem;
      T* adr;
    
    public:
      arrayof(int);
      ~arrayof();

      arrayof(const arrayof &);
      arrayof & operator = (const arrayof &);

      bool operator > (const arrayof &) const;
      bool operator >= (const arrayof &) const;
      bool operator < (const arrayof &) const;
      bool operator <= (const arrayof &) const;
      bool operator == (const arrayof &) const;
      bool operator != (const arrayof &) const;

      T & operator [] (int);

      void display();
};


template <typename T> arrayof<T>::arrayof(int size)
{
    nelem = size;
    adr = new T [nelem];	
}

template <typename T> arrayof<T>::~arrayof()
{
    delete [] adr;
}


template <typename T> arrayof<T>::arrayof(const arrayof & n)
{
    nelem = n.nelem;
    adr = new T [nelem];
    for (int i = 0; i < nelem; i++) adr[i] = n.adr[i];
}

template <typename T> arrayof<T> & arrayof<T>::operator = (const arrayof & n)
{
    if (this != &n)
    {
	delete [] adr;
	nelem = n.nelem;
	adr = new T [nelem];
	for (int i = 0; i < nelem; i++) adr[i] = n.adr[i];
    }
    return *this;
}

template <typename T> bool arrayof<T>::operator > (const arrayof & m) const
{
    if (nelem > m.nelem) return true;
    else
    {
	if (nelem == m.nelem)
	{
	    int i = nelem-1;
	    while (adr[i] == m.adr[i] && i > 0) i--;
	    if (adr[i] > m.adr[i]) return true;
	    else return false;	    
	}
	else return false;
    }
}

template <typename T> bool arrayof<T>::operator >= (const arrayof & m) const
{
    if (nelem > m.nelem) return true;
    else
    {
	if (nelem == m.nelem)
	{
	    int i = nelem-1;
	    while (adr[i] == m.adr[i] && i > 0) i--;
	    if (adr[i] >= m.adr[i]) return true;
	    else return false;	    
	}
	else return false;
    }
}

template <typename T> bool arrayof<T>::operator < (const arrayof & m) const
{
    if (nelem < m.nelem) return true;
    else
    {
	if (nelem == m.nelem)
	{
	    int i = nelem-1;
	    while (adr[i] == m.adr[i] && i > 0) i--;
	    if (adr[i] < m.adr[i]) return true;
	    else return false;	    
	}
	else return false;
    }
}

template <typename T> bool arrayof<T>::operator <= (const arrayof & m) const
{
    if (nelem < m.nelem) return true;
    else
    {
	if (nelem == m.nelem)
	{
	    int i = nelem-1;
	    while (adr[i] == m.adr[i] && i > 0) i--;
	    if (adr[i] <= m.adr[i]) return true;
	    else return false;	    
	}
	else return false;
    }
}

template <typename T> bool arrayof<T>::operator == (const arrayof & m) const
{
    if (nelem == m.nelem)
    {
	int i = nelem-1;
	while (adr[i] == m.adr[i] && i > 0) i--;
	if (adr[i] == m.adr[i]) return true;
	else return false;	    
    }
    else return false;
}

template <typename T> bool arrayof<T>::operator != (const arrayof & m) const
{
    if (nelem == m.nelem)
    {
	int i = nelem-1;
	while (adr[i] == m.adr[i] && i > 0) i--;
	if (adr[i] != m.adr[i]) return true;
	else return false;	    
    }
    else return true;
}


template <typename T> T & arrayof<T>::operator [] (int i)
{
    return adr[i];
}

template <typename T> void arrayof<T>::display()
{
    for (int i = nelem-1; i >= 0; i--) std::cout << adr[i] << " ";
    std::cout << std::endl;
}

