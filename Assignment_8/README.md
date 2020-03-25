# Assignment_8

## Weekly Project - External Events

### Requirements
Clone the [ofxJSON Addon](https://github.com/jeffcrouse/ofxJSON) and put it in the "addons" directory.

Get an API key on darksky.

Create a new project using ofxJSON.

Get latitude and longitude for any city on the planet.

Craft a "Forecast Request" URL for your city.

NYC Example: https://api.darksky.net/forecast/YOUR_KEY/42.3601,-71.0589

Make the request and print the resulting JSON out via cout.

Within the window print time (in epoch format), sunriseTime, sunsetTime, temperature, and two other values of your choice.

Use integer division to calculate and additionally print the current day of the year, hour, and minute. 

Translate 4 values from the above request to a visualization.

Create an appropriate GUI to manually force each value.  (show changes in your video)

Example: Use sunrise/sunset/hour to change the background color.  Use temperature to change the color of a leaf.

Prepare your first project for next week's crit.

### Description
In this project, the weather forecast data in this city(NYC) is from Dark Sky API. Five values are extracted from the resulting JSON file: Time, Temperature, Wind Speed, Sunrise Time and Sunset Time. The seene I simultaed is the view that I used to see in a classroom(D1208) on D12.

As time flows forward in one day, you are able to see that the light coming from two windows in the classroom is constantly changing. Both sunrise time and sunset time can be re-set manually through GUI panel and shown in the light changing progress. The background sound in this project is a wind sound effect. Its wolume is controlled by how strong the wind is. I also added one more button in GUI panel. This toggle is a light switch, with which lights in this room can be turned on and off.

### Screenshots

![](images/1.png)
![](images/2.png)
![](images/3.png)
![](images/4.png)
![](images/5.png)
![](images/6.png)
![](images/7.png)
![](images/8.png)

**Link to Youtube video:**

[![openFrameworks Week_8 Assignment](http://img.youtube.com/vi/NNaKc5a7T5c/0.jpg)](http://www.youtube.com/watch?v=NNaKc5a7T5c)

