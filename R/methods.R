setMethod("summary", 
          signature=c("sda"),
          function(object) return(object@backend$summary()))

Rsda <- function(x, y, hidden){
    sdaModule <- new(Sda)
    sdaModule$init(x, y, hidden)
    return(new("sda",
               backend=sdaModule))

}
