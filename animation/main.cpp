#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/VideoMode.hpp>
// Make code easier to type with using "using namespace"

#define WIDTH 1080;
#define HEIGHT 1920;

// using namespace sf;



// This is where our game starts
int main(int argc, char** argv){
    sf::VideoMode vm(1920, 1080);
    sf::RenderWindow window(vm, "Timber!!!", sf::Style::Fullscreen);    

    // Create a texture to hold a grpahic on the GPU
    sf::Texture textureBackground;

    // Load a graphic into the texture
    std::string const fileName = "graphics/background.png";
    textureBackground.loadFromFile(fileName);

    // Create a sprite
    sf::Sprite spriteBackground;

    // Attach the texture to the sprite
    spriteBackground.setTexture(textureBackground);

    // Set the sprite background to cover the screen
    sf::Vector2f spritePos = {0,0};
    spriteBackground.setPosition(spritePos);

    // =========================================================================='

    sf::Texture textureTree;
    const std::string& treeFile = "graphics/tree.png";
    textureTree.loadFromFile(treeFile);
    sf::Sprite spriteTree;
    spriteTree.setTexture(textureTree);
    sf::Vector2f treePos = {810, 0};
    spriteTree.setPosition(treePos);

    // Preparing the bee 
    sf::Texture textureBee;
    const std::string beeFile = "graphics/bee.png";
    textureBee.loadFromFile(beeFile);
    sf::Sprite spriteBee;
    spriteBee.setTexture(textureBee);
    sf::Vector2f beePos = {0, 800};
    spriteBee.setPosition(beePos);

    // Is the bee currently moving? 
    bool beeActive =  false;

    // How fast can the bee fly? 
    float beeSpeed = 0.0f;
    // Make 3 cloud sprite from one texture
    sf::Texture textureCloud;

    // Load 1 new texture
    const std::string& cloudFile = "graphics/cloud.png";
    textureCloud.loadFromFile(cloudFile);


    // 3 New sprites with the same texture 
    sf::Sprite spriteCloud1;
    sf::Sprite spriteCloud2;
    sf::Sprite spriteCloud3;

    spriteCloud1.setTexture(textureCloud);
    spriteCloud2.setTexture(textureCloud);
    spriteCloud3.setTexture(textureCloud);


    // Position the clouds on the left of the screen at different heights 
    spriteCloud1.setPosition(0,0);
    spriteCloud2.setPosition(0,250);
    spriteCloud3.setPosition(0,250);


    // Are the clouds currently on the screen? 
    bool cloud1Active = false;
    bool cloud2Active = false;
    bool cloud3Active = false;

    // How is fast is each cloud? 
    float cloud1Speed = 0.0f;
    float cloud2Speed = 0.0f;
    float cloud3Speed = 0.0f;

    while(window.isOpen()){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            window.close();
        }

        window.clear();


        // Draw our game scene here 
        window.draw(spriteBackground);
        
        // Draw the clouds
        window.draw(spriteCloud1);
        window.draw(spriteCloud2);
        window.draw(spriteCloud3);

        // Draw the tree
        window.draw(spriteTree);

        // Draw the insect
        window.draw(spriteBee);

        // Show everything we just drew
        window.display();
    }

    return 0;
}
