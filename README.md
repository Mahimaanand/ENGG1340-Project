# Waiting List for a Club
The Falconkeep Sanctuary Club is an extremely exclusive Hong Kong club that provides membership only to the most talented and influential individuals.
This project relates to making and managing the waiting list and the current members list of the club. 
Additionally, it will also dynamically change point weightages to ensure a diverse pool of members.

Prospective members are required to fill a form on basis of which they will be assessed and allotted a certain number of points, based on which they are ranked and given membership priority.

## Membership Form:
    Name:
    Reference (existing member's name):
    Date:
    Age:
    Income:
    Club Sport Skills:
      Golf-
      Swimming-
      Squash-
      Snooker-
  
### Point Allotment System:
The four criteria on which the prospective member would be assessed are Reference, Age, Income, and Club Sports Skills

The weightages are as follows (out of a total of 100):

     Reference (10 points): 
      If the member named in the reference is a part of the current member-list, then he will be alloted the point, 
      else no points
     
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
      Each sport will be rated out of 10 (initially*)
      
## User Interface
The following commands would be made available:
1. Make N: Creates N new membership positions that get filled up by the first N members of the waiting list.
2. Add filename: Adds person (whose membership form is stored in the file) to waiting list at appropriate position based on points. 
3. Remove name: Removes person whose name is given from member list and that position is filled up by the top member of waiting list.
4. Show w/m: Outputs entire waitlist/member list into a file.
5. Find A val: Outputs all members with val as value of attribute A. (eg: Find Income 600,000 would output all MEMBERS with that income).
6. Exit: Exits the program.

