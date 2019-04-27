# Waiting List for a Club
The Falconkeep Sanctuary Club is an extremely exclusive Hong Kong club that provides membership only to the most talented and influential individuals.
This project relates to making and managing the waiting list and the current member-list of the club. 
Additionally, it will also dynamically change point weightages to ensure a diverse pool of members.

Prospective members are required to fill a form on basis of which they will be assessed and allotted a certain number of points. They are ranked and given membership priority accordingly.

## Membership Form:
    Name:
    Reference (existing member's name):
    Age:
    Income:
    Club Sport Skills:
      Golf  Swimming    Squash  Snooker
  
### Point Allotment System:
The four criteria on which the prospective member would be assessed are Reference, Age, Income, and Club Sports Skills

The weightages are as follows (out of a total of 100):

     Reference (10 points): 
      If the member named in the reference is a part of the current member-list, then he will be alloted the point
      Else no points
     
     Age (20 points):
      <18 years: Membership application not applicable
      18-25 years: 15 points
      25-40 years: 20 points
      40-50 years: 10 points
      50+ years: 0 points
     
     Income (30 points):
      400,000-500,000 HKD: 10 points
      500,000-750,000 HKD: 15 points
      750,000-1 million HKD: 20 points
      >1 million HKD: 30 points
     
     Club Sport Skills (40 points):
      Each sport will be rated out of 10 (initially)
      
## User Interface
The following commands would be made available:
1. Make N: Creates N new membership positions that get filled up by the first N members of the waiting list. Outputs the name of members who are added, their member IDs, and the number of vacant positions (if any).
2. Add filename: Adds person (whose membership form is stored in the file) to waiting list at appropriate position based on points. It will print his/her points and current ranking in waiting list.
3. Remove ID: Removes person whose ID number is given; that position is filled up by the top member of waiting list.
4. Show w/m: (W)Outputs entire waitlist along with points and ranking. (M)Outputs member list along with member ID on console and into a file.
5. Find attribute: Prompts the user to search by name or age. It then displays a list of members that were found with the provided attribute along with their member IDs. 
6. Average A: Outputs average of the member list's sports scores for each sport.
7. Exit: Exits the program.

## Notable Features
This program will dynamically alter the weightages of the Club Skill Sports so that the Falconkeep Sanctuary Club can retain its sporting superiority and reputation of being an atheletic forerunner. If there is a deficit of skill in a certain sport category, the program would alter the weightages to give an edge to those members that could fill in the deficit.
For example, if the average scores for a certain sport is signifcantly lesser than the rest, then the weightages would increase for that sport and decrease accordingly for the rest.
When the Add menu command is given, the program would check if the membership form file has valid input values.

This project would come with an existing member list (stored in a file). When the Exit command is given, the member list at the time would be stored into that file and read upon startup to ensure continuity.

## Assumptions
At the start of the program, the waiting list would be empty and this waiting list would be discarded at the time of exiting.
The last line for each file of person to be added to waiting list must end without a '\n' character(i.e the line with sport score weightages should end as is, without a newline after it)
