#include "arrayofT.h"


class natural : public arrayof<char>
{
    private:
      void clean0();
      natural(int, char);
      bool minor(const natural &) const;
      bool majeq(const natural &) const;
      int digits(int);
      friend int random_int(int, int);
    
    public:
      natural(int);
      natural(const char*);
      //natural(string);

      friend natural operator + (const natural &, const natural &);
      friend natural operator - (const natural &, const natural &);
      friend natural operator * (const natural &, const natural &);
      friend natural operator / (const natural &, const natural &);
      friend natural operator % (const natural &, const natural &);
      friend natural operator ^ (const natural &, const natural &);

      void display();
      friend natural random_natural(int);
      friend natural random_natural(const natural &, const natural &);
      friend natural gcd(const natural &, const natural &);
};
