(define y 3)
y
(define foo(list 1 2 3 4 5 6))
(car foo)
(cdr foo)
(define e #t)
e

(define double
  (lambda(x)
    (* x 2)))
(double 2)
(double (double 2))
(display "--------------------------")
(newline)

(define absloute
  (lambda (x)
    (if (negative? x)
        (- x)
        x)))
(absloute -3)
(newline)
(define zeronumber
  (lambda (x)
    (if (zero? x)
        (x)
        (- x  x))))
(zeronumber 1)
(zeronumber 100)
(newline)
(define postivenumber
  (lambda (x)
    (if (positive? x)
        (x)
        (- x))))
(postivenumber -1)
(newline)
(define (triangular n)
  (if (= n 1)
      1
      (+ n (triangular (- n 1)))))

(display (triangular 10))
(newline)
(display (triangular 3))
(newline)
(define (power x n)
  (if (= n 0)
      1
      (* x (power x (- n 1)))))
(power 2 3)

(define greet
  (lambda(name)
    (display (string-append "hello" name ("!"))
             (display "What is yout favorite number?")
             (let((num(read)))
               (if(equal? num 5)
                  (begin
                    (display"Great!")
                            (display num)
                            (dis
             
                            
