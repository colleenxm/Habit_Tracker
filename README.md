# README

 * Overview 
 * Requirements
 * Installation
 * Code style
 * Demo
 * Citations 

## Overview 
I built a habit tracking app, which allows users to enter how many habits they would like to track and the names of each habit, and then check in periodically to record their progress. They can then see a simple, charted representation of their progress with each habit. 

## Requirements
* OpenFrameworks version 0.10.1 or higher. Some other versions of OpenFrameworks may generate errors. To install OpenFrameworks, follow the instructions at http://openframeworks.cc/download/ 

You will need to add ofxGui and ofxJSON to the project using OpenFrameworks. To do so, open OpenFrameworks' projectGenerator app (path/to/of/download/projectGenerator-osx or a similar path if you're installing this on another OS), import this project, and select ofxGui and ofxJSON under the drop-down menu in the Addons section.

## Installation
Installation is quite straightforward.
Steps:
1. git clone https://github.com/uiuc-sp19-cs126/final-project-colleenxm
2. Open in Microsoft Visual Studio or a similar IDE through OpenFramework's projectGenerator app.
3. Run.

## Code Style
I used  Google C++ Style Guide (https://google.github.io/styleguide/cppguide.html). Note that methods required by OpenFrameworks deviate from this style.

## Demo
For the sake of time, I only put the first and last stages of the app in the gif. First is when you are a new user, you create a user name and add the habits that you would like to track. Then, you check off whether or not you did them that day. The gif then pauses and skips to a further date in to better show the progress, although with regular use you can see that you can only track the progress one day at a time. In the second part of the gif, the app gets data from the JSON file created earlier with the user's name and asks for progress on the same habits, and then shows how the progress ocurred over a number of days. 

![demo](https://user-images.githubusercontent.com/42981164/57056118-f1753d80-6c65-11e9-83e4-1ae693d35083.gif)

## Citations
I used https://github.com/ElizWang/Enhanced_Pacman as an example for proper formatting in regards to all of my .md files, as well as an example for creating buttons. 

This example from ofxJSON https://github.com/jeffcrouse/ofxJSON/tree/master/example_file_read_write was also extremely useful in my code, as demonstrated writing to a JSON file using ofxJSON. 

I used ofxCenteredTrueTypeFont (https://github.com/armadillu/ofxCenteredTrueTypeFont) to format the text. I cloned this and added it in src/header_addons. 
