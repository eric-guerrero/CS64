#include "stdio.h"
#include "stdlib.h"

//Why do we have to assign the numerical expression of a bitwise operation to a variable (print)
//	Why can't why use it directly in our conditional statements
//Why does adding a += 1 mess up the operation by one, but only after the negation
//
int multiplyBy8(int v)
{
	// TODO: multiply the number by 8
	return v<<3;
}

int setBit6to1(int v)
{
	// TODO: set bit 6 to 1
	v = v|64;
	return v;
}

int setBit3to0(int v)
{
	// TODO: set bit 3 to 0
	int Bit3 = 8;
	Bit3 = ~Bit3;
	return v&Bit3;
}

int flipBit5(int v)
{
	// TODO: flip bit 5 (if it is 0, make it 1.  If 0, make 1)
	return v^32;
}

int ifBit7is0(int v)
{
	// TODO: check to see if bit 7 is a 0 - return 1 if true, 0 if false

	//Why is this wrong?
	int print = v&128;
	if((v & 128) == 0){
	return 1;
	}
	else{
	return 0;
	}
}

int ifBit3is1(int v)
{
	// check to see if bit 3 is a 1 - return 1 if true, 0 if false
	int print = v&8;
	if(print== 8){return 1;}
	else{return 0;}

}

int unsignedBits0through5(int v)
{
	// return the unsigned value in bits 0 through 5
	int bit = 63;

	return v&bit;
}

int unsignedBits6through9(int v)
{
	// return the unsigned value in bits 6 through 9
	int bit = 960;
	int beforeShift = v&bit;
	int afterShift = beforeShift>>6;
	return afterShift;
}

int signedBits0through5(int v)
{
// return the signed value in bits 0 through 5
	int neg = 65536;
	int posOrNeg = v&neg;
	//Most sig bit of v is a 1 (Negative)
	if(posOrNeg == neg){
		v = ~v;
		v += 1;
		int truncation = 63;
		int importantBits = v&truncation;
	        importantBits = ~importantBits + 1;
		//int toReturn = ~importantBits;
		return importantBits;
	   }

	else{
	//Most sig bit of v is a 0 (Positive)

		//Time to get 0 - 5 bits
		int truncation = 63;
		int importantBits = v&truncation;

		//Check if negative
		int negTrunc = 32;
		int posOrNegTrunc = importantBits&32;

		//Most sig bit of truncated number is 1 (Negative)
		if(posOrNegTrunc == negTrunc){
			importantBits ^= 63;
			//importantBits += 1;
			return ~importantBits;
		}

		else{
			//Most sig bit of truncated number i 0 (postitive)
			return importantBits;

		}


	}
	return 11;
}

int signedBits6through9(int v)
{
	// return the signed value in bits 6 through 9
	
	int neg = 65536;
	int posOrNeg = v&neg;
		//Find the truncated bit's most sig bit (pos 9)
		int negTrunc = 512;
		int posOrNegTrunc = v&negTrunc;
		if(posOrNegTrunc == negTrunc){
			//Trunc most sig bit is 1 (negative)
			v = v&960;
			int posNegBits = v>>6;
			//return posNegBits;
			int result = (posNegBits^15) ;//XOR to inverse and - 1
			//return posNegBits;

			return ~(result);
			}
		else{
			//Trunc most sig bit is 0 (positive)
			
			//bit shift to grab just the truncated bits
			v = v&960; //Scrub 
			int posPosBits = v>>6;
			return posPosBits;
		}
		return 1;
}

int setBits4through9(int v, int setValue)
{
	//return v;
	int neg = 65536;
	int posOrNeg = v&neg;
	if(posOrNeg == neg){
		//Negative number;
		setValue = (~setValue);//+1
		//return setValue;
		setValue = setValue&63;
		setValue = setValue<<4;
		//return setValue;
		v = (~v) +1;
		int temp = v&64527;//64543
		temp=temp|setValue;
		return (~temp)+1;
		
		//return v;
	}
	// set bits 4 through 9 in v to become setValue
	int temp = v&64543;//mask places 4-9 with 0's
	setValue = setValue&63; //Mask everything except the lowest bits
	setValue = setValue<<4;	//Bit shit to be in the proper place
	//return setValue;
	temp = temp|setValue;
	

	return  temp;


	return v;
}
