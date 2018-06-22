#include<iostream>
#include<fstream>
#include<iomanip>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<bitset>
#include<sstream>
#include<string>
#include<cstdio>
#include<cmath>

using namespace std;

class CacheLine
{
public:
	string tag;
	int dirty = 0;
	int data[8];
}CL;

int bin2dec(string s)
{
	long binary, dec = 0, r, b = 1, n;

	stringstream bb; // Using stringstream to convert binary string to integer decimal
        bb << dec << s;
        unsigned y;
        bb >> y;
        bitset<16> a(s);        

        n = a.to_ulong(); 
return n;/*
	while(n > 0)
	{
		r = n%10;
		dec = dec + r * b;
		b *= 2;
		n /= 10;
	}
	
return n;
*/

} 		



int main(int argc, char *argv[])
{
	ifstream fi;
	ofstream fo;

	fi.open(argv[1]);
	
	fo.open("dm-out.txt");

	int RAM[65563];
	CacheLine CL[32];

	char str[20];
	char* address;
	char* op;
	char* info;

	string tag;
	string line;
	string offset;
	string stradd;
	string add;
	
	int hit = 0;
	int lno;
	int adno;
	int offno;
	int infno;
	int tno;
	int Start;
	
	while(fi.getline(str, 11))
		{
			address = strtok(str, " ");
			op = strtok(NULL, " ");
			info = strtok(NULL, " ");

			stringstream ss;	//Using stringstream to open a new stream to store binary value
			ss << hex << address;   // Sending hexadecimal "string" values to stream
			unsigned x;
			ss >> x; 	       //Reading back from binary stream
			bitset<16> ad(x);     //Assigning either 0s or 1s to hex value in binary value stream
			stringstream sss;
			sss << hex << info;
			sss >> x;
			bitset<8> inn(x);

//			cout << ad.to_string() << endl; 
			
			stradd = ad.to_string();			
	
			tag = stradd.substr(0, 8); //assigning tag bits
			line = stradd.substr(8, 5); //assigning line number
			offset = stradd.substr(13, 3);   //assigning offset

			
 			//cout<<tag <<"  "<<line <<"  "<< offset <<"  ";

			lno = bin2dec(line); //converting line number to int	
			infno = bin2dec(inn.to_string()); // converting data info to int
     			
			tno = bin2dec(tag); // converting tag to int

			bool wasDirty = CL[lno].dirty;

		/*	if(tno == CL[lno].tag)*/	if(tag.compare(CL[lno].tag ) == 0 )
			{
				hit = 1; //hit
			}
	
			/*else if(tno != CL[lno].tag)	*/			else
			{
				hit = 0; //miss

				if( CL[lno].dirty == 1 )
				{
					add = CL[lno].tag + line + "000";
					
					Start = bin2dec(add);					

				/*	stringstream bb; // Using stringstream to convert binary string to integer decimal
					bb << dec << add;
					unsigned y;
					bb >> y;
					bitset<16> a(y);	

					Start = a.to_ulong(); //Changes to type long int
*/
					for(int j = 0; j <= 7; j++)
					{
						RAM[Start + j] = CL[lno].data[j];
					}

						//write back line into memory
				}

				adno = bin2dec(stradd);
				offno = bin2dec(offset);								
				for(int i = 0; i <= 7; i++)
				{
					CL[lno].data[i] = RAM[adno - offno + i]; //reading correct line of memory into cache line 							
				}

				CL[lno].tag = tag;
				
				CL[lno].dirty = 0; //reset dirty bit
			
			}				



		//	cout<<tokx<<" "<<toky<<" "<<tokz;
                                offno = bin2dec(offset); 
			if(!strcmp(op, "FF"))
			{
				CL[lno].dirty = 1;
				CL[lno].data[offno] = infno ; //write
			}
	
			else
			{
				fo << setw(2)  << uppercase << setfill('0') << setbase(16) << CL[lno].data[offno] << " " << hit << " " << wasDirty << endl; //read
			}

		}
return 0;
}							 	
		
	
