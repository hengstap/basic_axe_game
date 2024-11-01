#include "raylib.h"
int main() {
    // Window dimensions
    const int width = 800;
    const int height = 450;
    InitWindow(width, height, "Dsawse's Window");

    // Circle position
    int circle_x = 200;
    int circle_y = 200;

    //Circle Borders
    int circle_radius = 25;
    int l_circle_x = circle_x - circle_radius;
    int r_circle_x = circle_x + circle_radius;
    int t_circle_y = circle_y - circle_radius;
    int b_circle_y = circle_y + circle_radius;

    // axe position
    int axe_x = 400;
    int axe_y = 0;

    // axe borders
    int axe_length = 50;
    int l_axe_x = axe_x;
    int r_axe_x = axe_x + axe_length;
    int t_axe_y = axe_y;
    int b_axe_y = axe_y + axe_length;

    // Move Direction
    int direction = 10;

    // Set if there is a collision
    bool axe_collision = 
                (b_axe_y >= t_circle_y) && 
                (t_axe_y <= b_circle_y) && 
                (r_axe_x >= l_circle_x) && 
                (l_axe_x <= r_circle_x);


    // Game logic loop
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE); // Clear the screen with white color

        if (axe_collision) {
            DrawText("Game Over!", 400, 200, 20, RED);
        } else { 

            //Update the edges
            l_circle_x = circle_x - circle_radius;
            r_circle_x = circle_x + circle_radius;
            t_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;

            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_length;
            t_axe_y = axe_y;
            b_axe_y = axe_y + axe_length;    

            // Update the collision

            axe_collision = 
                (b_axe_y >= t_circle_y) && 
                (t_axe_y <= b_circle_y) && 
                (r_axe_x >= l_circle_x) && 
                (l_axe_x <= r_circle_x);

            DrawCircle(circle_x, circle_y, circle_radius, BLUE); // Draw a red circle at the position (circle_x, circle_y)

            DrawRectangle(axe_x, axe_y, axe_length, axe_length, RED); // Draw a red rectangle at the position (300, 0) to make an axe
        
            // Move the axe
            axe_y += direction;
            if (axe_y > height || axe_y < 0) {
                direction = -direction;
            }

            // Increase the speed of movement by increasing the value being added to the position.
            if (IsKeyDown(KEY_D) && circle_x < width) {
                circle_x += 10;  // increased from 5 to 10
            }
            if (IsKeyDown(KEY_A) && circle_x > 0) {
                circle_x -= 10;  // increased from 5 to 10
            }
            if (IsKeyDown(KEY_W) && circle_y > 0) {
                circle_y -= 10;  // increased from 5 to 
            }
            if (IsKeyDown(KEY_S) && circle_y < height) {
                circle_y += 10;  // increased from 5 to 10
            }
        } 
        EndDrawing(); // End the drawing frame  
    }
}