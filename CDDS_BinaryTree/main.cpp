#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"

#include "BinaryTree.h"
#include "TreeNode.h"
#include <iostream>

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------


    BinaryTree m_binaryTree;
    TreeNode* m_selectedNode = nullptr;

   /* for (int i = 0; i < 20; i++)*/
    for(int i = 5; i > 0; i--)
    {
        m_binaryTree.Insert(rand() % 100);

    }

    int valueBoxValue = 0;
    bool valueBoxEditMode = false;

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        GuiSetStyle(TEXTBOX, TEXT_ALIGNMENT, GUI_TEXT_ALIGN_CENTER);

        if (GuiValueBox(Rectangle{ 25, 25, 125, 30 }, NULL, &valueBoxValue, 0, 100, valueBoxEditMode)) valueBoxEditMode = !valueBoxEditMode;

        if (GuiButton(Rectangle{ 160, 25, 125, 30 }, GuiIconText(RICON_OK_TICK, "Insert")))
        {
            // Implement the code to insert valueBoxValue into your binary tree here! 
            m_binaryTree.Insert(valueBoxValue);
        }

        if (GuiButton(Rectangle{ 160, 60, 125, 30 }, GuiIconText(RICON_BIN, "Remove")))
        {
            // Implement the code to remove the node with value = valueBoxValue from your binary tree here! 
            m_binaryTree.Remove(valueBoxValue);
        }
        if (GuiButton(Rectangle{ 160, 95, 125, 30 }, GuiIconText(RICON_LENS, "Search")))
        {
            m_selectedNode = m_binaryTree.Find(valueBoxValue);
        }

        // draw the binary tree
        m_binaryTree.Draw(m_selectedNode);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}