setMethod("summary", 
          signature=c("da"),
          function(object) return(object@backend$summary()))

setMethod("train", 
          signature=c("da"),
          function(object) return(object@backend$train()))

setMethod("reconstruct",
          signature=c("da","matrix"),
          function(object,test) {
            return(object@backend$reconstruct(test))
          })

setMethod("setLearningRate",
          signature=c("da","numeric"),
          function(object, lr) {
            return(object@backend$setLearningRate(lr))
          })

setMethod("LearningRate",
          signature=c("da"),
          function(object) {
            info <- summary(object)           
            return(info$LearningRate)
          })

setMethod("setTrainingEpochs",
          signature=c("da","numeric"),
          function(object, te) {
            return(object@backend$setTrainingEpochs(te))
          })

setMethod("TrainingEpochs",
          signature=c("da"),
          function(object) {
            info <- summary(object)           
            return(info$TrainingEpochs)
          })

setMethod("setHiddenRepresentation",
          signature=c("da","numeric"),
          function(object, h) {
            return(object@backend$setHiddenRepresentation(h))
          })

setMethod("HiddenRepresentation",
          signature=c("da"),
          function(object) {
            info <- summary(object)           
            return(info$HiddenRepresentation)
          })

setMethod("setCorruptionLevel",
          signature=c("da","numeric"),
          function(object, cl) {
            return(object@backend$setCorruptionLevel(cl))
          })  

setMethod("CorruptionLevel",
          signature=c("da"),
          function(object) {
            info <- summary(object)           
            return(info$CorruptionLevel)
          })

Rda <- function(x){
    daModule <- new(dA)
    daModule$init(x)
    return(new("da", backend=daModule))
}
