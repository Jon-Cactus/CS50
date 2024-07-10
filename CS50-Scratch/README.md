# cs50x_notes
The purpose is to supplement my highly specialized frontend studies with a fundemental understanding of computer science as a whole, learn how to approach problems like a programmer, and not hide behind layers of abstraction.

# Project 0 - Scrath Project

## Outline
The goal of this game is to hit the gold brick with the ball. the ball must not hit the red barrier at the bottom, and normal bricks must be destroyed in order to reach the gold brick. Destroying the gold brick will grant access to the next level. There are a range of powerups that can be attained. 

## Checklist

Requirements:
- The ball must bounce off the paddle and choose a random direction between a set of degrees.
- If the ball hits the red zone, the game must reset.
- If the ball hits a brick, the ball must bounce off of the brick in a similar fashion to when it bounces off the paddle.
  - The brick must also "disappear" (really just move off screen).
- If the ball hits the gold brick, the game is won. 

Power-ups (this will have to become a stretch goal for later - I foresee this taking a lot of time):

big_ball:
as the name implies, this powerup makes the ball larger, and therefore easier to destroy bricks, and easier to catch.
```
when ball hits big_ball_powerup
  ball size increase by 10 for 10 seconds
  
```

big_paddle: 
similarly, this powerup makes the player's paddle larger, and therefore the ball is easier to catch.

```
When ball hits big_paddle_powerup
  paddle size increase by 10 for 30 seconds
  after 30 seconds, paddle returns to normal size
```

destructo:
this powerup makes the ball destroy everything in its path for 1 hit.

```
