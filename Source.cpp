#include <cmath>
#include <raylib.h>

class Circle
{
public:
    float x, y;
    float radius;
    Color color;

    Circle(float x, float y, float radius, Color color)
    {
        this->x = x;
        this->y = y;
        this->radius = radius;

        this->color = color;
    }

    void Draw()
    {
        DrawCircle(x, y, radius, color);
    }
};

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    float a = 0;


    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    float Radius = 100;
    
    float CenterX = screenWidth / 2;
    float CenterY = screenHeight / 2;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        Circle InsideCircle(cos(a) / (1/Radius) + CenterX, sin(a) / (1/Radius) + CenterY, 5, BLUE);

        BeginDrawing();

        ClearBackground(RAYWHITE);

        InsideCircle.Draw();
        DrawCircleLines(screenWidth / 2, screenHeight / 2, Radius, BLACK);

        if (IsKeyDown(KEY_D)) a += (3.0f * GetFrameTime());
        if (IsKeyDown(KEY_A)) a -= (3.0f * GetFrameTime());

        if (IsKeyDown(KEY_RIGHT)) Radius += (100.0f * GetFrameTime());
        if (IsKeyDown(KEY_LEFT) && Radius >= 0) Radius -= (100.0f * GetFrameTime());

        if (IsKeyDown(KEY_F)) CenterX += (10.0f * GetFrameTime());
        if (IsKeyDown(KEY_H)) CenterX -= (10.0f * GetFrameTime());


        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}