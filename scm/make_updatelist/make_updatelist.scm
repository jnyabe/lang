#!/usr/bin/env gosh
;;; -*- mode:gauche; coding: utf-8 -*-

(use sxml.serializer)
(use sxml.ssax)

(define elem_update_data_list '(*TOP* uppdate_data_list))
(define elem_fpdate '(force_update))
(define elem_region '(region (@ (id "jp"))))
(define elem_sys_pup '(system_pup))
(define elem_sysex_pup '(system_ex_pup))
(define elem_rec_pup '(recovery_pup))

(define doc '(list 
	      elem_update_data_list 
	      elem_region 
	      elem_sys_pup
	      elem_sysex_pup
	      elem_rec_pup))



(define (main args) ; entry point
  (srl:parameterizable
   doc
   (current-output-port)
   '(method . xml)
   '(indent . " ")
   '(omit-xml-declaration . #f)
   )
  )
