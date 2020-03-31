#Learning C++ Game Design

##Katie Foster, Shirin Kuppusamy, Mahima Beltur

We did a series of C++ game design tutorials in order to meet our learning goals of becoming familiar with C++ and how to apply C++ to game design. After encountering difficulties with the first tutorial that we selected, we altered our learning goal to encompass learning C++ in Linux, without the use of Visual Studio. Our MVP was to complete all the tutorials we identified as important, and our stretch goal was to collaboratively create a short game based on what we learned from the tutorials. We accomplished our stretch goal and were able to collaboratively develop a game that incorporated the elements we learned from the tutorials we completed. 

Our game/visualization consists of a window with a background image, an ambient background noise, and animal images. Upon left clicking the animal, it will produce a sound, and upon right clicking, the noise will end. 

The first component of the project was getting a background image to appear on the window:

 ``` 
  sf:: Texture texture;
  texture.loadFromFile("forest2.jpg");
  sf:: Sprite sprite_back;
  sprite_back.setTexture(texture);
 ```
    
The code above uses the sfml library to create an object of the Texture class that loads in the image from the given file. Then in order to place the image in a shape that can be displayed, we create a Sprite (a textured rectangle) set to the given Texture.

Following this, we needed to stream a constant background noise. To do this, we had to create a global variable 
```sf::Music music;``` such that the object is not destroyed within the function and rendered unusable in main. To play the music, we used the following function:
```
void playBackground()
  {
      music.openFromFile("resources/forest_ambience.wav");
      music.play();
      music.setLoop(true);
  }
  ```
This function opens the music file, plays it, and sets the loop to true to allow it to continue to play for however long the window is open. When this function is called in main, it can continue to to play as the rest of the sequence executes because music plays on its own thread in sfml. 

Creating the objects follows the same principle as creating the background image.

In order to recognize clicking on the image, we implemented a mouse click function:

```
if (event.type == sf::Event::MouseButtonPressed){
      if (event.mouseButton.button == sf::Mouse::Left){
        int x = event.mouseButton.x;
        int y = event.mouseButton.y;
 ```
 The event object was also globally defined. If the event type is MouseButtonPressed and if it is a Left click, then the integers x and y are set to the position of the mouse. If the x and y positions are within the area encompassed by a shape, then a button press is recongized and a sound is played. The following code presents an example:
 
 ```
   if(abs((x-25)-200)<25 && abs((y-25)-300)<25){
          std::cout << "Snake was pressed" << std::endl;
          playSound("resources/snakeHiss.wav");
 ```
 The playSound function shown above is detailed below:
 
```
  sf::SoundBuffer buffer;
  sf::Sound sound;
  sound.setBuffer(buffer);
  sound.play();
  sound.setLoop(true);
 ```
 This first segment of the function creates the SoundBuffer object and the Sound object. We use a Sound instead of a Music object here because the sounds are short enough that the audio data can be loaded in contrast to the ambient noise which could more effectively be streamed. It then plays the sound and sets the loop to true to continue playing the sound until it is stopped. Unfortunately, this code alone will not actually render a sound output because the sound is being repeatedly played with no pause to allow for processing. Thus, while the sound is playing, we add a sleep statement:
 
 ```
   while (sound.getStatus() == sf::Sound::Playing)
  {
    sf::sleep(sf::milliseconds(100));
  }
  ```
The last component of this function is to stop the sound and break out of the function ```sound.stop();``` if the mouse is right clicked. This follows a similar structure as the left click code detailed above.

One design decision we made was to encapsulate large chunks of code into functions and then call them in main. This posed a challenge because like other variables, sfml objects are not usable outside of the scope in which they were defined. Yet, in order for the functions to work as intended, operations need to be performed on the music, event, and window objects outside of the functions in which they are primarily used (the same instance of some of them are also used in multiple functions). Thus, we made the design decision to declare some variables globally, especially since we are working only in one .cpp file, and encapsulate code in fuctions. This was primarily advantageous because it helped make the flow of the code clearer, and it avoided repetition of large segments of code. 

Overall, we learned a lot from this project. We learned basic C++ syntax and declaration options. We also learned how to use the sfml library. Furthermore, we achieved our learning goals of working with game design and using the tutorials we referred to in order to create an end product. In essence, we all learned a lot about how to work with the sfml library and c++ and feel more comfortable now being able to use this knowledge to create more complex projects in future. We were able to accomplish more than we'd hoped for, and overall feel satisfied. One thing we began experimenting with and want to look at more in future is using classes. Our above decision choice could have been simplified further by using self-defined classes and a more object oriented approach, so that is something we want to study more moving forward.

To play our game, run the following commands:
```
g++ -c game.cpp
g++ game.o -o sfml-app -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
./sfml-app
```
Enjoy!


  

