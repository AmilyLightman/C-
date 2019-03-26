#include <iostream>
#include <ColorSync>
#include <cstring>// #include <String.hh>
using namespace std;
class String{
private:
    char* p;
    uint32_t len;
    uint32_t capacity;
    String stringlen(const char* p){
        uint32_t count = 0;
        while (* str++!='\0')  // have to fix , watch vedio
            count++;
        return count;

    }
public:
    String(): len(0), p(nullptr){}
    ~String(){delete [] p;}
    String (const char str[]): len(strlen(str)), p(new char(len)) {//String (const char * const p)
        for(int i=0;i<len;i++)
        {
            p[i]=str[i];// never s++, it changes s; s must be left
        }
        // memcpy(p,str,len); faster for large blocks
        String (const String& orig): len(orig.len), p (new char[len]);{
           if (orig.len >8) {
               uint64_t * src = (uint64_t *) orig.p;
               uint64_t * dest= (uint64_t *) p;
               uint32_t count;
               for( count =len; len>=8; len-=8){
                   *dest ++ = *src ++;
               }
               char* pdest = (char*)dest;
               char* psrc = (char*)src;
               for( ;count > 0; count--){
                   *pdest ++ = *psrc ++;
               }
           }
        }
    }
    String& operator =(const String& orig){
        string copy(orig); //copy just a name
        len= orig.len;
        swap(p, copy.p);
        return *this;
    }
    char operator[] (const uint32_t pos) const {return p[pos];}
    char& operator[] (uint32_t pos) const {return p[pos];}

};
int main() {
    String s;
    String s2="abc"; // a b c '\0' control-@ (ASCII NUL)
    s2+="def";
    String copy(s2);
    String copy2 =2;
    String x = "qqq";
    copy =x;
    String s3("xyz", 5); //xyzxyzxyzxyzxyz
    String s4 = s3.substring(3,2);//from position 3 length 2
    cout << s4;
    char c= s3[3];
    s3[4]= 'a';
    cout<< s3;
    s3.replace('x','q');
    s3.insert(5, hello);
    const String hello = "hello";
    String s5 = s2 + s3;
    cout << s5 << '\n';
    return 0;
}

#if 0


int main() {
    Bitmap b(30, 20); // 30 pixels across, 20 pixels high, each pixel RGBA(8bits/ uint32_t )
// top left pixel =(0,0)
    Color RED= (255,0,0); // all red , no green, no blue(fully opaque)
    Color BLUE= (0,255,0);
    Color GREEN= (0,0,255);
    Color WHITE= (255,255,255);

    b.line(0,0, 19,19, RED);
    b.line(0,5, 29,10, BLUE);
    b.horizLine(0,20,19, GREEN);
    b.vertLine(5,0,19, GREEN);
    b.fillRect(10,10,4,3, BLACK);// x=10, y=10 w=4, h=3
    b.Rect(10,10,4,3, WHITE);// x=10, y=10 w=4, h=3
    b.ellipse(15, 0, 8,5, RED);// ellipse centered at (15,0) w=8, h=5
    return 0;
}
#endif