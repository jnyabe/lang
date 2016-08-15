#!/usr/bin/env gosh

(define (main args)
  (if (null? (cdr args))
      (sql-parse (cdr args))
      