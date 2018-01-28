;;*****************************************************************************
;;
;;	Assembly language subroutine
;;
;;		Author: 		Gary J. Minden
;;		Organization:	KU/EECS/EECS 388
;;		Date:			2014-04-18
;;		Version:		1.0
;;
;;		Purpose:		Assembly language subroutine
;;
;;		Notes:
;;
;;*****************************************************************************
;;

;;
;;	This subroutine computes a value based on four input arguements.
;;	The arguments are assumed to be in CPU registers R0 - R3
;;	  (AKA A1 - A4)
;;

;;	Declare sections and external references

		.global		AsmCompute				; Declare entry point as a global symbol
		.text								; Program sections

AsmCompute:									; Entry point

;;
;;	Save necessary registers
;;
;;	Since this subroutine does not use registers other than R0 - R3,
;;	  and we do not call another subroutine, we don't need to save
;;	  any registers.
;;

;;
;;	Allocate local variables on the Stack
;;
;;	Since this subroutine does not have local variables,
;;	  no Stack space need be allocated.
;;

;;
;; This solves the X value and returns the result in R0
;; CXValue = A * C & A * D & D + C | B;
;; R0 A
;; R1 B
;; R2 C
;; R3 D
;; R4
;; R5
;; R6
;; R7

		MUL		R4,R0,R2
		MUL		R5,R0,R3
		ADDS	R6,R3,R2
		ANDS	R4,R4,R5 ; this is correct
		ANDS	R4,R4,R6 ; this is correct
		ORRS	R4,R4,R1 ; this is correct

;;
;;This solves the Y value  and returns the result in R0
;; Y =  D / A & D + C * A | D
;;

		MUL		R5,R2,R0
		ADDS	R5,R5,R3
		UDIV	R6,R3,R0
		ANDS	R5,R5,R6
		ORRS	R5,R5,R3

;; Gives back X + Y value.

		ADDS	R0, R4, R5
;;
;;	Return from the subroutine with the result in R0
;;
		BX			LR				; Branch to the program address in the Link Register
		.end
