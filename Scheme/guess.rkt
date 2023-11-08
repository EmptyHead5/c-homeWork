(#%require(lib"27.ss" "srfi"))
(random-source-randomize! default-random-source)
(define correct (+ (random-integer 100) 1))
; Assign the target number to "correct" by defining it.
(define (guessing-game correct count)
  (display "Guess a number from 1 to 100: ")
  (let ((guess (read)))
    (cond ((> guess correct)
           ;Use the “cout” keyword for judgment statements with more than two entries. Otherwise, use “if” for judgment statements up to two.
           (display "Higher... Enter another guess: ")
           (guessing-game correct (+ count 1)))
          (( < guess correct)
           (display "Lower... Enter another guess: ")
           (guessing-game correct (+ count 1)))
          (else
           (display "Correct!")
            (display count)
            (display " guesses... Please enter your name: ")
           (let ((name (read)))
             (display "Good game, ")
             (display name)
             (newline))))))

; 
(guessing-game correct 0)
