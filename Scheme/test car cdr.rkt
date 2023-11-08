(define L'(1(2 3) ((4) () (5 6))))
(cdr (car (cdr L)))
(car(car(cdr (cdr L))))
(car(car(cdr(cdr(car(cdr (cdr L)))))))
(cdr(car(cdr(cdr(car(cdr (cdr L)))))))
(define list-sum
  (lambda (L)
    (if(null? L)
       0
       (+ (car L)(list-sum (cdr L))))))
(newline)
       (list-sum '( 1 2 3))
       
       