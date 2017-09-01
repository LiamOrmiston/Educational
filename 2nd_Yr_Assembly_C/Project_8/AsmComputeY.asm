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

		.global		AsmComputeY				; Declare entry point as a global symbol

		.text								; Program sections

AsmComputeY:									; Entry point

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
;;This solves the Y value  and returns the result in R0
;; Y =  (D / A) & ((D + (C * A)) | D )
;;

		MUL		R2,R2,R0
		ADDS		R2,R2,R3
		ORRS		R2,R2,R3
		UDIV		R3,R3,R0
		ANDS		R0,R3,R2



;;
;;	Return from the subroutine with the result in R0
;;
		BX			LR				; Branch to the program address in the Link Register

		.end





