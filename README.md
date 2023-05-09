[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-718a45dd9cf7e7f842a935f5ebbe5719a5e09af4491e668f4dbf3b35d5cca122.svg)](https://classroom.github.com/online_ide?assignment_repo_id=10931401&assignment_repo_type=AssignmentRepo)

# Movie Recommender
 
 Authors: [Daniel Shao](https://github.com/dzshao), [Aaron Hudec](https://github.com/aaronhudec), [Jalen Shen](https://github.com/jleans), [Johann Rivera](https://github.com/Johann-R)


## Project Description
Almost everyone loves movies, so this is a project that is appealing for us to make and will be useful for others to use. This project is a great opportunity to learn the new tools and skills introduced in CS100 and beyond, as we also get to practice web scraping and algorithm design.

The project will use C++, Visual Studio Code, Git, GitHub, gdb, valgrind, Vim, CMake, GoogleTest, and web scraping. 

User can input the name of a movie, genre, director, actor, as well as a rating range. The program will output a list of list of up to ten movie recommendations to watch including their rating, release date and other general information. The movies are sorted based on their rating. 

The program will scrape information from movie websites such as imdb to obtain relevant information. The project can be used by anyone to receive quick and convenient recommendations for their movie watching sprees. It makes it much more simple to expand one’s movie interests, consolidating the entire process into one program.

 > ## Phase II
 > In addition to completing the "User Interface Specification" and "Class Diagram" sections below, you will need to:
 > * Create an "Epic" (note) for each feature. Place these epics in the `Product Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Break down the "Epics" into smaller actionable user stories (i.e. smaller development tasks). Convert them into issues and assign them to team members. Place these in the `TODO` column.
 >   * These cards should represent roughly 7 days worth of development time for your team. Then, once the sprint is over you should be repeating these steps to plan a new sprint, taking you until your second scrum meeting with the reader in phase III.
 > * Schedule two check-ins using Calendly. You need to pick both time slots during your lab on week 6. Your entire team must be present for both check-ins.
 >   * The first check-in needs to be scheduled with your lab TA. During that meeting, you will discuss your project design/class diagram from phase II.
 >   * The second check-in should be scheduled with a reader. During that meeting you will discuss:
 >     * The tasks you are planning for the first sprint
 >     * How work will be divided between the team members
## User Interface Specification
 > Include a navigation diagram for your screens and the layout of each of those screens as desribed below. For all the layouts/diagrams, you can use any tool such as PowerPoint or a drawing program. (Specification requirement is adapted from [this template](https://redirect.cs.umbc.edu/~mgrass2/cmsc345/Template_UI.doc))

### Navigation Diagram
> Here is our [example](nachart2.PNG). This diagram depicts the paths a user can take through our program. Starting at the main menu when they launch the program, they are filled in on what the program does and immediately prompted for which criteria they would like to earch by. After choosing their criteria, the user can choose what tier of ratings they would like to sort by. After choosing the ratings, the user will then enter the keywords they are sorting by and confirm once they are done entering them. They will then receive a list of recommendations, and an option to generate another list of recommendations off of the same criteria or return to the main menu, where they can input another set of criteria to search by. 


### Screen Layouts
> Main page with a prompt that recommends 10 movies based on various criteria. The various criteria is a text box one can add various keywords to, such as director, genre, actors, themes, etc. User will also be prompted on what the average ratings of the movies will be. Keywords will be entered one by one, pressing enter each time to input the next keyword. Finish entering keywords by entering E to confirm. Once all keywords are entered the user is sent to a page with 10 movies. Each movie will have a link to a page with info about it, a short blurb about the movie, and keywords about the movie listed.
After movies are listed, users can enter x or some other letter to exit and go back to the main page.  (If movies not found that match keywords after being excluded, we can recommend movies at random)


Example interface interaction:

Welcome to Cinefile! We will recommend 10 movies based on the keywords that you will enter. We can recommend movies based on multiple categories: titles (T), genres (G), directors (D) ,and actors (A). What criteria would you like to search by? Enter the letter corresponding to your desired category. 

> T

You would like to search by title. Would you like highly rated movies (H) , poorly rated movies (P), or averagely rated movies (A)? Please enter the letter corresponding to the ratings you would like. 

> A

Please enter each keyword individually, hitting “ENTER” between each one. Once you have entered all your keywords, please enter “C” to confirm your keywords.

>fire
>superhero
>funny
>niche
>the rock
>C

Confirmed! Generating your custom list of movie recommendations…

1: Mario Movie 
(link to imdb or wikipedia here) (link to trailer)
Mario bros go on wacky adventure from new york or whatever 
Keywords: trending, game, mario, chris pratt, family
etc.

Press X to return to the main page.

>X


## Class Diagram
 > Include a **class diagram(s)** for your project and a **description** of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper UML notation (as discussed in the course slides).

Class Descriptions:

scrapeWebsite
    - scrapeSite(...) member function which scrapes the input website URL and returns the HTML code of the site as a string.
imdbScraper
    - scrapeGenres(...) member function which scrapes the input genre’s or combination of genres for the top associated movies on IMDb. Returns vector of URLs to those movie’s IMDb pages.
    - scrapeMovie(...) member function which scrapes the input IMDb movie URL and returns the HTML code of the page as a string. 
moviesDatabase
    - Aggregation of Genres
    - storeGenreLists() member function stores the list of genres and all their contained movies within a file.
    - loadGenreLists() member function loads the list of genres and their contained movies from the saved file
Genre
    - Aggregation of movies
    - Stores name of the genre and an unordered_map of Movie objects as a list of associated movies.
    - populate(...) member function which adds the given movie object to the 
Movie (struct)
    - Aggregation of genres, actors, and directors
    - Struct with dumb data such as the title, release year, rating, as well as sets of Actors, Director, and Genre objects.
MovieRecommender
    - recommend(...) overloaded member function which returns a priority_queue of movie recommendations. 
Person
    - Stores a set of movies the Person is associated with.
    - Subclasses: Actor, Director
UserInterface
    - Member functions to facilitate user interaction, such as printMainMenu() and printMovieList().
 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
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
 
