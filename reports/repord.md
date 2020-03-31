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
  

