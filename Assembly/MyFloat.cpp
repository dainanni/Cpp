#include "MyFloat.h"
#include <cmath>
MyFloat::MyFloat(){
  sign = 0;
  exponent = 0;
  mantissa = 0;
}

MyFloat::MyFloat(float f){
  unpackFloat(f);
}

MyFloat::MyFloat(const MyFloat & rhs){
	sign = rhs.sign;
	exponent = rhs.exponent;
	mantissa = rhs.mantissa;
}

ostream& operator<<(std::ostream &strm, const MyFloat &f){
	strm << f.packFloat();
	return strm;

}




MyFloat MyFloat::operator+(const MyFloat& rhs) const{
	unsigned int tempm1, tempm2, man;
	tempm1 = this->mantissa;
	tempm2 = rhs.mantissa;
	unsigned int exp = 0;
	unsigned int retsign = 0;

	tempm1 = tempm1 | (1 << 23);
	tempm2 = tempm2 | (1 << 23);
	
	unsigned int expdiff;
	if(this->exponent < rhs.exponent)
	{
		expdiff = rhs.exponent - this->exponent;
		if(expdiff < 8)
		{
			exp = this->exponent;
			tempm2 <<= expdiff;
		}
		else
		{
			exp = rhs.exponent;
			if((tempm1 >> (expdiff - 1)) & 1 && this->sign != rhs.sign)
			{
      	tempm1 >>= expdiff;
				tempm1 += 1;
			}
			else
			  tempm1 >>= expdiff;
		}
	}
	else
	{
		expdiff = this->exponent - rhs.exponent;
		if(expdiff <= 8)
		{
			exp = rhs.exponent;
			tempm1 <<= expdiff;
		}
		else
		{
      exp = this->exponent;
      if((tempm2 >> (expdiff - 1)) & 1 && this->sign != rhs.sign)
      {
        tempm2 >>= expdiff;
        tempm2 += 1;
			}
			else
        tempm2 >>= expdiff;
		}
	}
	if(this->sign == rhs.sign)
	{
		man = tempm1 + tempm2;
		retsign = this->sign;
	}
	else
	{
		if(tempm1 == tempm2)
		{
			man = 0;
			exp = 0;
			retsign = 0;
		}
		else if(tempm1 > tempm2)
		{
			man = tempm1 - tempm2;
			retsign = this->sign;
		}
		else
		{
			man = tempm2 - tempm1;
			retsign = rhs.sign;
		}
	}
	

	
	while(man & 0xff000000)
	{
		man >>= 1;
		exp++;
	}
	man = man & 0x7fffff;
	
	MyFloat temp;
	temp.mantissa = man;
	temp.exponent = exp;
	temp.sign = retsign;

	return temp;
}

MyFloat MyFloat::operator-(const MyFloat& rhs) const{
	MyFloat temp(rhs);
	temp.sign = !(temp.sign);
	return *this + temp;
}

bool MyFloat::operator==(const float rhs) const{
	MyFloat rhs2(rhs);
	return (sign == rhs2.sign && exponent == rhs2.exponent && mantissa == rhs2.mantissa);
}

void MyFloat::unpackFloat(float f) {
	__asm__(
		"push %%ebx;"
		"movl %[f], %%ebx;"
		"andl $(0x7fffff), %%ebx;"
		"movl %%ebx, %[mantissa];"
		"movl %[f], %%ebx;"
		"shrl $23, %%ebx;"
		"andl $(0xff), %%ebx;"
		"movl %%ebx, %[exponent];"
		"movl %[f], %%ebx;"
		"shrl $31, %%ebx;"
		"andl $1, %%ebx;"
		"movl %%ebx, %[sign];"
		"pop %%ebx"
		:
		[mantissa] "=a" (mantissa),
		[exponent] "=d" (exponent),
		[sign] "=c" (sign)
		:
		[f] "m" (f)
		:
		"cc"
  );

}//unpackFloat

float MyFloat::packFloat() const{
  //returns the floating point number represented by this
  float f = 0;
  __asm__(
  	"movl %[sign], %[f];"
  	"shll $8, %[f];"
  	"orl %[exponent], %[f];"
  	"shll $23, %[f];"
  	"orl %[mantissa], %[f]"
  	:
  	[f] "=a" (f)
  	:
  	[exponent] "g" (exponent), 
  	[mantissa] "g" (mantissa),
  	[sign] "g" (sign)
  	:
  	"cc"
  );
  return f;
}//packFloat
//



