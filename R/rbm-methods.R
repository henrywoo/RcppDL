setMethod("summary", 
          signature=c("rbm"),
          function(object) return(object@backend$summary()))

setMethod("train", 
          signature=c("rbm"),
          function(object) return(object@backend$train()))

setMethod("reconstruct",
          signature=c("rbm","matrix"),
          function(object,test) {
            return(object@backend$reconstruct(test))
          })

setMethod("setLearningRate",
          signature=c("rbm","numeric"),
          function(object, lr) {
            return(object@backend$setLearningRate(lr))
          })

setMethod("LearningRate",
          signature=c("rbm"),
          function(object) {
            info <- summary(object)           
            return(info$LearningRate)
          })

setMethod("setTrainingEpochs",
          signature=c("rbm","numeric"),
          function(object, te) {
            return(object@backend$setTrainingEpochs(te))
          })

setMethod("TrainingEpochs",
          signature=c("rbm"),
          function(object) {
            info <- summary(object)           
            return(info$TrainingEpochs)
          })

setMethod("setHiddenRepresentation",
          signature=c("rbm","numeric"),
          function(object, h) {
            return(object@backend$setHiddenRepresentation(h))
          })

setMethod("HiddenRepresentation",
          signature=c("rbm"),
          function(object) {
            info <- summary(object)           
            return(info$HiddenRepresentation)
          })

setMethod("setStep",
          signature=c("rbm","numeric"),
          function(object, s) {
            return(object@backend$setStep(s))
          })

setMethod("Step",
          signature=c("rbm"),
          function(object) {
            info <- summary(object)           
            return(info$ContrastiveDivergenceStep)
          })

Rrbm <- function(x){
    rbmModule <- new(Rbm)
    rbmModule$init(x)
    return(new("rbm", backend=rbmModule))
}
