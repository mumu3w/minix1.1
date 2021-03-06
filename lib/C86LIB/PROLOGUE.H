;	prologue.h	
;	standard prologue for c86 assembly code

;	if you set @COMFILE, the COM memory model 
;	will be selected
@COMFILE	equ	0

;	@BIGCODE means far procedures
;	@BIGDATA means 4 byte data pointers

@bigcode	equ	(@bigmodel or @medmodel)
@bigdata	equ	@bigmodel

;	DEFINE ARGUMENT BASE RELATIVE FROM BP

IF	@BIGCODE
@AB	EQU	6
ELSE
@AB	EQU	4
ENDIF

@CODE	SEGMENT BYTE PUBLIC 'CODE'
@CODE	ENDS
@DATAB	SEGMENT PARA PUBLIC 'DATAB'
@DATAB	ENDS
@DATAC	SEGMENT BYTE PUBLIC 'DATAC'
@sb	label	byte
@sw	label	word
@DATAC	ENDS
@DATAI	SEGMENT BYTE PUBLIC 'DATAI'
@ib	label	byte
@iw	label	word
@DATAI	ENDS
@DATAT	SEGMENT BYTE PUBLIC 'DATAT'
@DATAT	ENDS
@DATAU	SEGMENT BYTE PUBLIC 'DATAU'
@ub	label	byte
@uw	label	word
@DATAU	ENDS
@DATAV	SEGMENT BYTE PUBLIC 'DATAV'
@DATAV	ENDS


if		@COMFILE
DGROUP	GROUP	@CODE,@DATAB,@DATAC,@DATAI,@DATAT,@DATAU,@DATAV
@CODE	SEGMENT BYTE PUBLIC 'CODE'
	ASSUME	CS:DGROUP,DS:DGROUP
else
DGROUP	GROUP	@DATAB,@DATAC,@DATAI,@DATAT,@DATAU,@DATAV
@CODE	SEGMENT BYTE PUBLIC 'CODE'
	ASSUME	CS:@CODE,DS:DGROUP
endif


;	END OF PROLOGUE.h
