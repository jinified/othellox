(TeX-add-style-hook
 "report"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-class-options
                     '(("article" "12pt")))
   (TeX-add-to-alist 'LaTeX-provided-package-options
                     '(("geometry" "margin=0.8in") ("inputenc" "utf8") ("amsmath" "fleqn") ("caption" "font=scriptsize" "labelfont=bf")))
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "path")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "url")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "nolinkurl")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "hyperbaseurl")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "hyperimage")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "hyperref")
   (add-to-list 'LaTeX-verbatim-macros-with-delims-local "path")
   (add-to-list 'LaTeX-verbatim-macros-with-delims-local "url")
   (TeX-run-style-hooks
    "latex2e"
    "article"
    "art12"
    "float"
    "geometry"
    "inputenc"
    "amsmath"
    "times"
    "hyperref"
    "multirow"
    "graphicx"
    "mathptmx"
    "caption"
    "csquotes")
   (LaTeX-add-labels
    "fig:minimax"
    "fig:negamax"
    "fig:alphabeta"
    "fig:bitboard_legalmoves"
    "fig:parallel_depth"
    "fig:traversal_model"
    "fig:speedup_model"
    "fig:hybridstyles"
    "fig:speedup_models"
    "fig:communication_ratio"
    "fig:alltoall"
    "fig:pvs"
    "fig:speedup_processor"
    "fig:classification_nodes")
   (LaTeX-add-bibliographies
    "ref"))
 :latex)

