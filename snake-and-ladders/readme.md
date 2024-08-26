## Notes
* Starting point and ending cant have a snake mouth
* Same point should not have a snake mouth and a ladder
    - for every x to y ladder, we check if x is not in snakes
* There could be another snake/ladder at the tail of the snake or
  the end position of the ladder and the piece should go up/down accordingly.
* There wont be an infinite loop of snake and ladder
    - If snake goes from x to y, we cant add y to x in ladder mapping