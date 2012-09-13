Om te beginnen met het developpen van onze software moet er eerst een omgeving worden opgezet.


# Windows: 

Download en installeer AVRStudio4:
http://www.atmel.com/Images/AvrStudio4Setup.exe

Download daarna WinAVR:
http://sourceforge.net/projects/winavr/files/latest/download?source=files

Sla WinAVR niet op in een path waar () in voorkomt, dus niet in bijv.
Program Files(x86). Dan krijg je alleen maar errors.


"So now when you have WinAVR and in 4.19 you start a new avr-gcc project 
when you come to build you will get some mysterious errors which are really saying 
"I don't know where/how to run the compiler". So for each project you create you then 
have to use Config Options on the Project menu and in the 5th tab fill in the 
paths to make.exe and avr-gcc.exe as: 


\winavr\bin\avr-gcc.exe 
\winavr\utils\bin\make.exe 

EDIT: Wanneer je met C++ gaat programmeren ipv in C moet je bij de eerste deze hebben:
\winavr\bin\avr-g++.exe 


Then it will work. This is then stored in the project settings so you just need 
to remember to set these things each time you create a new avr-gcc project. 
