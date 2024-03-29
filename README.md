# CS540-Programming-Assignment-3-Logical_Address_To_Physical_Address

Implementing Memory Management and Address Translation with C++ on Visual Studio.

- This code will randomly generate logical addresses and translate them to physical addresses in hex. It will also print out the page number and an offset in hex.
- The code declares and initializes const variables; page_size, frame_size, num_pages, and num_frames.
- It has a logical address generator function, and a page fault function. If a page isn't loaded into memory, the page fault function will load the page into the next available frame in secondary memory. If there are no available frames, there will be an error message.
- It uses a vector data structure for the page/frame table.
- The program properly maps the logical pages numbers to physical frame numbers.
- It handles cases for invalid page numbers. 

- In this program, you will only need to run it.
- To see the full effects of the code, go to line 42 and change "i<5 to i<10" from the for loop (// function to translate logical address to physical address, and providing the page numbers and offset). Making this change will allow for generating enough logical addresses to create scenarios for the page_faults function. 

------------------------------------------------------------------------------------------------------------------------------------------
OPENING THE PROGRAM:
- Open the Visual Studio Solution file --> Assignment 3 - Amy Kieu.sln --> on the top left, press view "solution explorer" --> double click "Assignment 3 - Amy Kieu" --> go to the drop down arrow on source files --> double click "Assignment 3 - Amy Kieu.cpp"
- At the top in the middle, select --> Local Windows Debugger (to run the code)

------------------------------------------------------------------------------------------------------------------------------------------
