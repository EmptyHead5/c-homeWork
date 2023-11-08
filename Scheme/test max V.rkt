(define L '(1 2 31 4 5 66))

(define max-list
  (lambda (lst)
    (if (null? (cdr lst))       
        (car lst)             
        (if (> (car lst) (car (cdr lst)))
            (car lst)
            (max-list (cdr lst))))))

(display (max-list L))
