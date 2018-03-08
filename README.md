# README

    /////////////////////////////////////////////////////////////
    / SWtESB 1.0 Changelog - Star Wars: the Empire Strikes Back /
    / Notes: This is a derived codebase from SWFotE 1.4 FUSS    /
    /////////////////////////////////////////////////////////////
    /         ________________.  ___     .______                /
    /        /                | /   \    |   _  \               /
    /       |   (-----|  |----`/  ^  \   |  |_)  |              /
    /        \   \    |  |    /  /_\  \  |      /               /
    /   .-----)   |   |  |   /  _____  \ |  |\  \-------.       /
    /   |________/    |__|  /__/     \__\| _| `.________|       /
    /        ____    __    ____  ___     .______    ________.   /
    /        \   \  /  \  /   / /   \    |   _  \  /        |   /
    /         \   \/    \/   / /  ^  \   |  |_)  ||   (-----`   /
    /          \            / /  /_\  \  |      /  \   \        /
    /           \    /\    / /  _____  \ |  |\  \---)   |       /
    /            \__/  \__/ /__/     \__\|__| `._______/        /
    /                                                           /
    /                                  The Empire Strikes Back  /
    /                                                           /
    /////////////////////////////////////////////////////////////
    / Modified by Paolo (Marduk) Francioso                      /
    /////////////////////////////////////////////////////////////

## How to start

Git Clone or download project. Go to src folder:
- make clean
- make

Best way to boot the mud is "nohup startup <port> &" in src directory.
'nohup' is an abbreviation of 'no halt user process', which prevents 
killing the mud's process when you logoff your user in the shell.
You can also type sh qstart from src folder. Default Port is 9500.
You can change it in startup file.

For an easier start to get your mud going, there is a premade
level 36 administrator named 'admin'. The password is 'admin'.

You should immediately change your name and password. This obviously goes 
without saying, but. Who knows.

## Changelog Abstract

-----------------------1st March 2018------------------------
- Cleaned Boards Directory
- Fixed mail management. The right HELP is suggested now

---------------------28th February 2018----------------------
- Fixed the backup procedure to propery store *.tar files in
  the Backup Directory
- Disabled automatic cleanup (autopurge)
  
---------------------27th February 2018----------------------
- Modified WHO command in order better display results
- Modified TITLE management and relative HELP
- Added PCRENAME Wiz Command
- Fixed HELP Command to run a default help
- Fixed The code to be compiled error/warning free in GCC 7.2
- Fixed several issues in SWFotE 1.4 FUSS Code
- Added MSET <victim> forcetype 1/2 command as wiz
- Fixed Identify Force Ability to run as Sense
- Fixed and removed useless helps
- Fixed force_lightning force skill
- Fixed a bug in colors declaration
- Fixed several pointers as nullptr for better consistence
- Removed ASSIGN_GSN in db.c for unused spells/skills for clean 
  startup


