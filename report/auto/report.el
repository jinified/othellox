(TeX-add-style-hook
 "report"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-class-options
                     '(("article" "12pt")))
   (TeX-add-to-alist 'LaTeX-provided-package-options
                     '(("geometry" "margin=0.8in") ("inputenc" "utf8") ("amsmath" "fleqn") ("caption" "font=scriptsize" "labelfont=bf")))
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
    "caption")
   (LaTeX-add-bibliographies
    "ref"))
 :latex)

