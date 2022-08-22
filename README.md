<h2 style="text-align: center;">Pathfinder</h2>
Aim of this project was to create pathfinding algorithm that can find the shortes rout from one point in the maze to another. I also created maze class that can procedurally create maze of given size and given start and end points.
<h2 style="text-align: center;">How to start</h2>
This project uses SFML library so you need to have it installed. If you are using Visual Studio after downloading this repo everything should be fine. If you are using other editors I sugest you follow the instructions given on the official site of library.

After compiling and firing the aplication you will see menu. First you need to choose the size of maze using up and down arrows for Y dimension and right and left arrows for X dimensions. Then you need to chose the algorithm type. After that maze is going to be generated, solved and path that is shortes is going to be shown on the screan. If you don't see maze after long while that means that chosen maze size is too big for chosen algorithm
<h2 style="text-align: center;">Algorithms</h2>
There are two algorithms in this project and I'm plaing on adding more.
<h3>Recursive</h3>
This algorith was fully created by me from the ground up and is using recursion to find path. Because of that it is slower and slower as the maze is becoming bigger. Trying to remove loops from the code doesn't really affect the perforaffect, if I were to remove all of the loop probably only then would the program run better.
<h3>Sample</h3>
This is sample alogorith which is one of the most popular algorithms. It is much faster than recursive one because it only uses loops. I took the discription of this algorithm for wekipedia.
<h2 style="text-align: center;">Test data</h2>
I ran five tryies of sample algorithm with 50% fill and squere maze with sizes from 2 to 52 and typed in the time into the included excel file. I averaged the time for each size and calculated deviation. Deviation increases with increasing  size. All of the numbers may not be correct because I only ran the algorithm five ( it would be better if I had at least 20 times) times for each size, but this results can give good understanding of corelation betwean size of maze and time it takes the algorithm to find the path.
<h2 style="text-align: center;">General Thoughts</h2>
This was a fast project and I definetly need to add some things like selection of the starting and finishing point from the menu and how much filling the maze has. This thing can only be done from the code at the moment. I would also change some desing. I also would like to create new algorith from the ground up, but this time I will try to make it work better
<h2 style="text-align: center;">Buggs</h2>
At this moment in time creating maze from file will not probably because space values are negative. In the future I will probably add separate values for maze creation with file and for internal use.
