(define L '(1 2 31 4 5 66 3 4 44 1222))

(define max-list
  (lambda (lst)
    (if (null? (cdr lst))       
        (car lst)             
        (if (> (car lst) (max-list (cdr lst)))
            (car lst)
            (max-list (cdr lst))))))

(display (max-list L))
   (random)
     