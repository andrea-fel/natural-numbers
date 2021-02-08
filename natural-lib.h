#include <string>

class natural
{
    private:
      int nelem;
      char * adr;
      
      natural(int, int);

      void clean0();
      friend int digits(int);
      
      int findIndex(const natural &) const;
      bool isSmallerThan(const natural &) const;
      bool isLargerOrEqualTo(const natural &) const;

      friend char randomInt(int, int);
    
    public:
      natural(int);
      natural(const char*);
      natural(std::string);
      ~natural();
      
      natural(const natural &);
      natural & operator = (const natural &);
      
      char & operator [] (int) const;
      int size() const;
      void display();
      
      friend bool operator > (const natural &, const natural &);
      friend bool operator >= (const natural &, const natural &);
      friend bool operator < (const natural &, const natural &);
      friend bool operator <= (const natural &, const natural &);
      friend bool operator == (const natural &, const natural &);
      friend bool operator != (const natural &, const natural &);
      
      natural & operator += (const natural &);
      natural & operator -= (const natural &);
      natural & operator *= (const natural &);
      natural & operator /= (const natural &);
      natural & operator %= (const natural &);
      
      natural & operator ++ ();
      natural operator ++ (int);
      natural & operator -- ();
      natural operator -- (int);

      friend natural operator + (natural, const natural &);
      friend natural operator - (natural, const natural &);
      friend natural operator * (natural, const natural &);
      friend natural operator / (natural, const natural &);
      friend natural operator % (natural, const natural &);
      friend natural operator ^ (const natural &, const natural &);

      friend natural randomNatural(int);
      friend natural randomNatural(const natural &, const natural &);
      friend natural gcd(const natural &, const natural &);
};
