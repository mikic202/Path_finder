<h2 style="text-align: center;">Pathfinder</h2>
Aim of this project was to create pathfinding algorithm that can find the shortes rout from one point in the maze to another. A maze class that can procedurally create a maze of a given size and given start and end points was also created.
<h2 style="text-align: center;">How to start</h2>
This project uses SFML library so you need to have it installed. If you are using Visual Studio after downloading this repository, everything should be fine. If you are using other editors I sugest you follow the instructions given on the official site of library.

After compiling and starting the application, you will see the main menu. First, you need to choose the size of the maze using up and down arrows for Y dimensions and right and left arrows for X dimensions. Then you need to chose the algorithm type. After that maze is going to be generated, solved and path that is shortes is going to be shown on the screan. If you don't see maze after long while that means that chosen maze size is too big for chosen algorithm
<h2 style="text-align: center;">Algorithms</h2>
There are two algorithms in this project and I'm planning on adding more.
<h3>Recursive</h3>
This algorithm was fully created by me from the ground up and uses recursion to find the path. Because of that, it gets slower and slower as the maze gets bigger. Trying to remove loops from the code doesn't really affect the performance. If I were to remove all of the loops, only then would the program run better.
<h3>Sample</h3>
This is sample alogorith which is one of the most popular algorithms. It is much faster than recursive one because it only uses loops. I took the discription of this algorithm for wekipedia.
<h2 style="text-align: center;">Test data</h2>
I tested five runs of the sample algorithm with 50% fill and square maze with sizes from 2 to 52 and typed in the time into the included Excel file. I averaged the time for each size and calculated deviation. Deviation increases with increasing  size. All of the numbers may not be correct because I only ran algorithm five ( it would be better if I had at least 20 times) times for each size, but these results can give a good understanding of the correlation between the size of the maze and the time it takes the algorithm to find the path.
<h2 style="text-align: center;">General Thoughts</h2>
This was a fast project and I definetly need to add some things like selection of the starting and finishing point from the menu and how much filling the maze has. This thing can only be done from the code at the moment. I would also change some desing. I also would like to create a new algorithm from the ground up, but this time, I will try to make it work better.
