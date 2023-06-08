[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=10931401&assignment_repo_type=AssignmentRepo)

# Movie Recommender
 [![CI](https://github.com/cs100/final-project-ahude001-dshao009-jshen075-jrive141/actions/workflows/main.yml/badge.svg)](https://github.com/cs100/final-project-ahude001-dshao009-jshen075-jrive141/actions/workflows/main.yml)
 
 Authors: [Daniel Shao](https://github.com/dzshao), [Aaron Hudec](https://github.com/aaronhudec), [Jalen Shen](https://github.com/jleans), [Johann Rivera](https://github.com/Johann-R)


## Project Description
Almost everyone loves movies, so this is a project that is appealing for us to make and will be useful for others to use. This project is a great opportunity to learn the new tools and skills introduced in CS100 and beyond, as we also get to practice web scraping and algorithm design.

The project will use C++, Visual Studio Code, Git, GitHub, gdb, valgrind, Vim, CMake, GoogleTest, and cURL. 

User can input the name of a movie, genre, director, actor, as well as a rating range. The program will output a list of list of up to ten movie recommendations to watch including their rating, release date and other general information. The movies are sorted based on their rating. 

The program will scrape information from movie websites such as imdb to obtain relevant information. The project can be used by anyone to receive quick and convenient recommendations for their movie watching sprees. It makes it much more simple to expand one’s movie interests, consolidating the entire process into one program.

## User Interface Specification
 
### Navigation Diagram
![Navigation Diagram](https://github.com/cs100/final-project-ahude001-dshao009-jshen075-jrive141/blob/master/Design%20Documents/navigation_chart_final.png?raw=true) 
This diagram depicts the path a user takes throughout the execution of the program. Starting at the main menu when they launch the program, they are filled in on what the program does and immediately taken to prompts which determine the list of movie recommendations they will receive. 

The user must choose what tier of ratings they would like to search for (this acts as the sole determiner of results if the user chooses to not enter any search keywords later). After choosing the rating range, the user will then then enter three more prompts to gather search keywords: one for genres, another for directors, and finally for actors. The user will enter their keywords and "finish" when they are done; the user may enter finish to skip the search for that specific keyword type. They will then receive a list of movie recommendations, and an option to exit the program or return to the main menu to begin a new search.


### Screen Layouts
Main page with a prompt that recommends 10 movies based on various criteria. The various criteria is a text box one can add various keywords to, such as director, genre, actors, themes, etc. User will also be prompted on what the average ratings of the movies will be. Keywords will be entered one by one, pressing enter each time to input the next keyword. Finish entering keywords by entering E to confirm. Once all keywords are entered the user is sent to a page with 10 movies. Each movie will have a link to a page with info about it, a short blurb about the movie, and keywords about the movie listed.
After movies are listed, users can enter x or some other letter to exit and go back to the main page.  (If movies not found that match keywords after being excluded, we can recommend movies at random)

### Example interface interaction:

Welcome to Cinefile! We will recommend up to 10 movies based on keywords you enter.<br>
First, are you looking for movies which are highly rated (H), average rated (A), or poorly rated (P)? Please enter the corresponding letter.<br>

> H

Great! We'll only recommend movies that are highly rated.<br>

We're going to ask you for the names of genres, directors, and actors to act as keywords.<br>
We'll then take those keywords and find movies related to them.<br>
If you do not want to input all 5 keywords for a group, input 'finished' as a keyword when you are done.<br>
If you do not put in any keywords, we will just show you random movies within your rating range.<br>

Let's start with genres. Enter up to 5, or enter 'finished' when you are done if you have less than 5.<br>

>Horror<br>
>Drama<br>
>finished

Now, how about directors? Enter up to 5, or enter 'finished' when you are done if you have less than 5.

>Guillermo Del Toro<br>
>Ari Aster<br>
>finished

Finally, what about actors? Enter up to 5, or enter 'finished' when you are done if you have less than 5.

>finished

Okay, for genres you input keyword(s): horror, drama<br>
For directors, you input keyword(s): guillermo del toro, ari aster<br>
For actors, you didn't input any keywords.<br>

Here's your list of movie recommendations:<br>

Hereditary (2018):<br>
Rating: 7.3/10<br>
Genre(s): Horror, Mystery, Thriller, Drama<br>
Director(s): Ari Aster<br>
Starring: Toni Collette, Alex Wolff, Milly Shapiro<br>

Pan's Labyrinth (2006):<br>
Rating: 8.2/10<br>
Genre(s): Drama, Fantasy, War<br>
Director(s): Guillermo Del Toro<br>
Starring: Ivana Baquero, Ariadna Gil, Sergi López<br>
...<br>

If you wish to exit, enter Y. If you want to get another set of movie recommendations, enter N.

>Y

Thank you for using Cinefile!


## Class Diagram 
![UML Class Diagram](https://github.com/cs100/final-project-ahude001-dshao009-jshen075-jrive141/blob/master/Design%20Documents/UML%20Class%20Diagram%20Final.png?raw=true)



### Class Descriptions:
Upon initialization, the program will create a MovieDatabase object. This object will store all the movies and genres that have already been parsed. The program functions by then using the UserInterface class to print out a menu prompting the user for how they would like to be recommended movies, based on a rating range and/or based on genres, directors, actors. Once the user has decided, the main function will call the appropriate recommend function. The recommend function will call the scrapeGenre or scrapeMovie function from the imdbParser class which uses web scraping to find movies that match the criteria desired by the user. These two functions will use scrapeSite in order to scrape the HTML of desired website. If a movie found is already stored in MovieDatabase, it will not create a new movie object. Otherwise, a new movie object will be created using the parseMovie() function, which calls the findActorList, findDirectorList, findGenreList, findName, and findRating functions. This new movie object will be added to the MovieDatabase and to the movie set of its respective Genre objects. The top ten movies scraped with the most similarities to what the user wants will be returned. Once the recommend function has found these ten movies, it will return them in a priority_queue. The function printMovieList will print out the ten movies to the user. 
- scrapeWebsite
  - scrapeSite(...) scrapes the input website URL and returns the HTML code of the site as a string.
  - write_callback(...) 
- imdbParser
  - scrapeGenres(...) calls scrapeWebsite::scrapeSite(...) on the IMDb page which lists the top movies associated with the input genre or combination of genres. Calls scrapeMovies(...) to fill a vector of Movie objects with the scraped data which will then be returned.
  - scrapeMovies(...) creates Movie objects with the corresponding 'find' member functions and fills an input vector of Movie objects with them.
  - findDirectorList(...) takes in a stringstream obtained from scrapeWebsite::scrapeSite(...) and returns a vector of the Director objects associated with a movie.
  - findActorList(...) takes in a stringstream obtained from scrapeWebsite::scrapeSite(...) and returns a vector of the Actor objects associated with a movie.
  - findGenreList(...) takes in a stringstream obtained from scrapeWebsite::scrapeSite(...) and returns a vector of the Genre objects associated with a movie.
  - findTitle(...) takes in a stringstream obtained from scrapeWebsite::scrapeSite(...) returns the title.
  - findRating(...) takes in a stringstream obtained from scrapeWebsite::scrapeSite(...) and returns the rating.
  - findReleaseDate(...) takes in a stringstream obtained from scrapeWebsite::scrapeSite(...) and returns the release date.
  - findHTML(...) helper function which finds a certan input string within the input stringstream.
  - skipLines(...) helper function which skips a certain number of input lines in the input stringstream.
- moviesDatabase
  - Aggregation of Genres
  - storeGenreLists() member function stores the list of genres and all their contained movies within a file.
  - loadGenreLists() member function loads the list of genres and their contained movies from the saved file
- Genre
  - Aggregation of movies
  - Stores name of the genre and an unordered_map of Movie objects as a list of associated movies.
  - populate(...) member function which adds the given movie object to the 
- Movie (struct)
  - Aggregation of genres, actors, and directors
  - Struct with dumb data such as the title, release year, rating, as well as sets of Actors, Director, and Genre objects.
- MovieRecommender
  - recommend(...) overloaded member function which returns a priority_queue of movie recommendations. 
- Person
  - Stores a set of movies the Person is associated with.
  - Subclasses: Actor, Director
- UserInterface
  - printWelcomeMessage() prints the welcome screen upon starting the program
  - printMovieList(...) takes in a list of movies returned from the MovieRecommender class to print.
  - printKeywordInstructions() prints instructions for the user regarding genre/director/actor keyword prompts.
  - printKeywords(...) prints back the list of all keywords the user entered during keyword prompts.
  - printRatingsType(...) prints a specific message related to the rating tier a user chose in getRatingsType()
  - getCharInput() prompts the user to enter a single character with input validation.
  - getSearchKeywords(...) loop to enter a certain number of keywords for a keyword prompt.
  - getKeyword(...) gets a single keyword from user input with input validation.
  - getRatingsType() prompts the user to pick a rating tier for movie recommendations.
  - getLoopExitInput() prompts the user to exit the program or return to the main menu at the end of execution.
 
We added a new, abstract "MovieWebsiteParser" class to adhere to the dependency inversion principle. Instead of using the imdbParser class, our program will instead use the abstract MovieWebsiteParser class. Having the imdbParser class inherit from the MovieWebsiteParser class makes expanding functionality to movie websites other than IMDb much easier in the future. Rather than restricting us to just using IMDb, we can now easily create new classes for other movie websites that won't break the functionality of the program. This change makes our code much more flexible, maintainable, and open for future improvements.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
