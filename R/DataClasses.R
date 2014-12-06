
setClass("deeplearning", representation("VIRTUAL"))

setClass("sda", representation(backend="C++Object"), contains=c("deeplearning"))
