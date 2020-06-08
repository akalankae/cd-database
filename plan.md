**Plan for the CD database program**

* Text based program
* A special CD data structure is defined. It will hold details about a CD.
* Database will consist of records (binary files) that contain written CD
  structures.
* User can interact with the database using the program.
* What user can do:
  - Write a new record with CDs.
  - Remove a stored record.
  - View a record: single CD entry OR all entries.
  - Save a record under a different name.
  - Add new CD entries to a record.
* Records will have *.dat* filename extension.

**Plan for program functions**
1. *Writing a new record*:
   a. read the record name. (must end with .dat)
   b. verify named record DOES NOT exist.
   c. get the number of CDs user want to enter
   d. write CDs to record

2. *Removing a stored record*:
   a. display names of available records (must end with .dat)
   b. read the record name.
   c. verify named record exists.
   d. display CD titles in the record.
   e. prompt to proceed with deletion.
   f. delete the record.

3. *View a record*:
   a. display names of available records (must end with .dat)
   b. read the record number user needs.
   c. display CDs in the record.

4. *View a single entry of a record*:
   a. display names of available records (must end with .dat)
   b. read the record number user needs.
   c. display CD titles in the record.
   d. get which CD the user wants. (better to read in CD number)
   e. verify named CD exists. (i.e. CD number)
   f. display that CD.

5. *Save record under different name*:
   a. display names of available records (must end with .dat)
   b. read the record number user needs.
   c. read new name user wants to save record as.
   d. verify record with the new name does not exist.
   e. write the contents of the original record to the new record.

6. *Add new entries to a record*:
   a. read the record name
   b. verify named record exists.
   c. display CD titles in the record.
   d. read number of CDs user want to enter
   e. write CDs at the end of the record.
