//
// Created by acsel on 06/09/2024.
//


struct Vector2i {
    int x;
    int y;

   Vector2i operator+(Vector2i const& other) {
       x += other.x;
       y += other.y;
       return *this;
   }

   Vector2i operator-(Vector2i const& other){
     x -= other.x;
     y -= other.y;
     return *this;
   }

   Vector2i operator*(Vector2i const& other){
     x *= other.x;
     y *= other.y;
     return *this;
   }

   Vector2i operator/(Vector2i const& other){
     x /= other.x;
     y /= other.y;
     return *this;
   }
};
