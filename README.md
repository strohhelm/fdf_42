# FDF
## The first graphical project!
This project is about creating a simple wireframe model representation of a 3D land- scape by connecting various points (x, y, z) with lines.

The program has to represent the model in isometric projection for the mandatory part.
The bonus part included rotation translation and zooming. Also i added colour changes and isolated z value increase via mouse scrolling.

The coordinates of the landscape are stored in a .fdf file passed as a parameter to your program. Here is an example:
```
$>cat 42.fdf
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
$>
```

Each number represents a point in space:
- The horizontal position corresponds to its axis.
- The vertical position corresponds to its ordinate.
- The value corresponds to its altitude.

The example file renders this:

![rendering](/screenshots/7.png)

There are 3 most interesting parts about this project that i remember specifically.
- Firstly the use of an external library. Leraning how to write code using a specific library, understanding its functions and efficiently using them was the main learning goal for this project. At least thats how i interpreted the subject. It was very fun to dip my toes into graphical rendering using the MLX42 library which is a wrapper for the glfw library. Its meant to make it extremely easy to use without much experience and quite well documented.
It was fun and interesting to get into the specific working of this library.

- Secondly i learned about the Bresenham line drawing algorithm. Since i had to draw straight pixel lines on screen, i was eager to implement a function that connects any two points (x, y) on the screen. It was quite easy to understand the algorithm but regardless of that, it still took me some time to make it error proof and truly work with any two points.
  
- Lastly was the main part of the Project problem: Calculating in 3 dimensions. since the input gave x, y and z values, i had to relearn calculating with 3d vectors and matrices. It was a lot of fun and a lot if typo correction to get it corrently implemented. But when it worked in the end, it was absolutely amazing.
Having this clear of a usecase for these calculations, would have helped me tremendeously in school when i first learned about them.

## Usage
Clone the repository and build the executable
```
git clone git@github.com:strohhelm/fdf_42.git && cd fdf_42 && make
```
or for bonus part, which is obioiusly the better program:
```
git clone git@github.com:strohhelm/fdf_42.git && cd fdf_42 && make bonus
```
then run the executable and choose a .fdf file as the first argument'
```
./fdf_bonus test_maps/42.fdf
```


### Here are some example screenshots of the rendering:

![stuff](/screenshots/1.png)
⬆️ i
This was the first time i tried to visualize the grid and i it was incredible and hilarious to see this messed up but not crashing image. I held on to this screenshot in memory of that moment :)

![stuff](/screenshots/2.png)
![stuff](/screenshots/3.png)
![stuff](/screenshots/4.png)
![stuff](/screenshots/5.png)
![stuff](/screenshots/6.png)
