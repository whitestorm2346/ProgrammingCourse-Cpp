#include <iostream>

using namespace std;

class control{
public:
   int id;
   int width;
   int height;
   void resize(int const w, int const h, bool const redraw = true){
      width = w;
      height = h;
      if(redraw)
         draw();
   }
   void draw(){
      cout << "control::draw\n";
   }
};
class image : virtual public control{
public:
   int stretch_style;
   int stretch_direction;
   void draw(){
      //執行 control 的 draw()
      control::draw();
      cout << "image::draw\n";
   }
};
class button : virtual public control{
public:
   int text_alignment;
   void draw(){
      //執行 control 的 draw()
      control::draw();
      cout << "button::draw\n";
   }
};
class image_button : public image, public button{
public:
   int content_alignment;
   void draw(){
      //執行 button 的 draw()
      button::draw();
      //執行 image 的 draw()
      image::draw();
      cout << "image_button::draw\n";
   }
};

//cannot modify
int main(){
   image i;
   i.id = 1;
   i.resize(32, 32);

   button b;
   b.id = 2;
   b.resize(100, 20);

   image_button ib;
   ib.id = 3;
   ib.resize(100, 20);

   return 0;
}
